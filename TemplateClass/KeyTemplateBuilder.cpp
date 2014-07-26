#include "stdafx.h"
#include "KeyTemplateBuilder.h"

CKeyTemplateBuilder::CKeyTemplateBuilder(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    bool bResult = false;
    CIntKey kIntKey;
    kIntKey.kValue = 2;
    m_kMultiDerived.Add( kIntKey );
    bResult = m_kMultiDerived.Keys< CIntKey, PropertyA >()[ 0 ].kValue == kIntKey.kValue;
    assert( bResult );

    CFloatKey kFloatKey;
    kFloatKey.kValue = 3.f;
    m_kMultiDerived.Add( kFloatKey );
    bResult = m_kMultiDerived.Keys< CFloatKey, PropertyB >()[ 0 ].kValue == kFloatKey.kValue;
    assert( bResult );

    PropertyA nValueA = 0;
    m_kMultiDerived.GetProperty( 0.f, nValueA );

    PropertyB nValueB = 0;
    m_kMultiDerived.GetProperty( 0.f, nValueB );

    m_kMultiDerived.RemoveFirstKey< CIntKey, PropertyA >();
    bResult = m_kMultiDerived.Keys< CIntKey, PropertyA >().size() == 0;
    assert( bResult );

    m_kMultiDerived.RemoveFirstKey< CFloatKey, PropertyB >();
    bResult = m_kMultiDerived.Keys< CFloatKey, PropertyB >().size() == 0;
    assert( bResult );

    CULKey kULKey;
    m_kSingleDerived.Add( kULKey );
    bResult = m_kSingleDerived.Keys()[ 0 ].kValue == kULKey.kValue;
    assert( bResult );

    PropertyC nValueC = 0;
    m_kSingleDerived.GetProperty( 0.f, nValueC );

    m_kSingleDerived.RemoveFirstKey();
    bResult = m_kSingleDerived.Keys().size() == 0;
    assert( bResult );
}

CKeyTemplateBuilder::~CKeyTemplateBuilder()
{

}
