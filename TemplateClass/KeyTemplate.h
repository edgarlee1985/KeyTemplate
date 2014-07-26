#include <assert.h>
#include <iostream>

typedef int PropertyA;
typedef float PropertyB;
typedef unsigned long PropertyC;

class CTimeKey
{
public:
    CTimeKey(){}
    virtual ~CTimeKey(){}
public:
    float fTime;
};

class CIntKey : public CTimeKey
{
public:
    CIntKey(){}
    virtual ~CIntKey(){}
public:
    PropertyA kValue;
};

class CFloatKey : public CTimeKey
{
public:
    CFloatKey(){}
    virtual ~CFloatKey(){}
public:
    PropertyB kValue;
};

class CULKey : public CTimeKey
{
public:
    CULKey(){}
    virtual ~CULKey(){}
public:
    PropertyC kValue;
};

#define SingleKeyTemplateFunc( C, K, P )           \
    using CKeyTemplate< C, K, P >::Add;            \
    using CKeyTemplate< C, K, P >::RemoveFirstKey; \
    using CKeyTemplate< C, K, P >::GetProperty;    \
    using CKeyTemplate< C, K, P >::Keys;

template< typename C, typename K, typename P >
class CKeyTemplate
{
public:
    CKeyTemplate( std::vector< K >& kKeys ) : m_kKeys( kKeys ) {}
    virtual ~CKeyTemplate(){}

    void Add( K kKey ){ m_kKeys.push_back( kKey ); }
    void RemoveFirstKey(){ m_kKeys.erase( m_kKeys.begin() ); }
    const std::vector< K >& Keys(){ return m_kKeys; }

    void GetProperty( float fTime, P& kValue );

protected:
    std::vector< K >& m_kKeys;
};

template< typename C, typename K, typename P >
inline void CKeyTemplate< typename C, typename K, typename P >::GetProperty( float fTime, P& kValue )
{
    static_cast< C* >(this)->CalcProperty( fTime, kValue );
}

class MultiDerivedClass
    : private CKeyTemplate< MultiDerivedClass, CIntKey, PropertyA >
    , private CKeyTemplate< MultiDerivedClass, CFloatKey, PropertyB >
{
public:
    MultiDerivedClass()
        : CKeyTemplate< MultiDerivedClass, CIntKey, PropertyA >::CKeyTemplate( m_kIntKeys )
        , CKeyTemplate< MultiDerivedClass, CFloatKey, PropertyB >::CKeyTemplate( m_kFloatKeys )
    {
    }
    virtual ~MultiDerivedClass(){}

    SingleKeyTemplateFunc( MultiDerivedClass, CIntKey, PropertyA );
    SingleKeyTemplateFunc( MultiDerivedClass, CFloatKey, PropertyB );

    template< typename K, typename P >
    const std::vector< K >& Keys()
    {
        return CKeyTemplate< MultiDerivedClass, K, P >::Keys();
    }

    template< typename K, typename P >
    void RemoveFirstKey()
    {
        CKeyTemplate< MultiDerivedClass, K, P >::RemoveFirstKey();
    }

    void CalcProperty( float fTime, PropertyA& kValue )
    {
        assert( !"Multi Class : PropertyA" );
    }

    void CalcProperty( float fTime, PropertyB& kValue )
    {
        assert( !"Multi Class : PropertyB" );
    }

protected:
    std::vector< CIntKey > m_kIntKeys;
    std::vector< CFloatKey > m_kFloatKeys;
};

class SingleDerivedClass : private CKeyTemplate< SingleDerivedClass, CULKey, PropertyC >
{
public:
    SingleDerivedClass()
        : CKeyTemplate< SingleDerivedClass, CULKey, PropertyC >::CKeyTemplate( m_kULKeys )
    {
    }
    virtual ~SingleDerivedClass(){}

    SingleKeyTemplateFunc( SingleDerivedClass, CULKey, PropertyC );

    void CalcProperty( float fTime, PropertyC& kValue )
    {
        assert( !"Signle Class : PropertyC" );
    }

protected:
    std::vector< CULKey > m_kULKeys;
};