/*
 * Copyright(C) 2004 ������ ���
 *
 * ���� ���� �������� ����������, ����������
 * �������������� �������� ������ ���.
 *
 * ����� ����� ����� ����� �� ����� ���� �����������,
 * ����������, ���������� �� ������ �����,
 * ������������ ��� �������������� ����� ��������,
 * ���������������, �������� �� ���� � ��� ��
 * ����� ������������ ������� ��� ����������������
 * ���������� ���������� � ��������� ������ ���.
 */

/*!
 * \file $RCSfile$
 * \version $Revision$
 * \date $Date::                           $
 * \author $Author$
 *
 * \brief ����� �����.
 */

#ifndef _CPLIB_BLOB_H_INCLUDED
#define _CPLIB_BLOB_H_INCLUDED

#include <algorithm>
#include <list>
#include <cplib/StringProxy.h>

namespace CryptoPro {

/**
 * \class CBlob Blob.h <cplib/Blob.h>
 * \brief �������� ������������������ ������������ �����.
 *
 * ����� ������������ ��� �������� �������� ������������������.
 * ����� �������������� ��� ��� �������� �������������� ASN.1 ��������,
 * ��� � ��� �������� ������������ �������� ������.
 *
 */
class CPLIB_CLASS CBlob
{
public:
    /// ������� ������ ������
    CBlob();
    /**
     * \brief ������� � �������������� ������
     *
     * \param ptr [in] ��������� �� ������ ������ ���������� � ������
     * \param length [in] ����� ������ � ������
     * \remarks ��� ������������� ������ ������� ������ ��� ��������
     * ������ � �������� �� ���� �� ���������� � ��������� ptr �����.
     */
    CBlob(const unsigned char *ptr, unsigned long length );
    /**
     * \brief ������� ������
     *
     * \param length [in] ����� ������ � ������
     * \remarks ��� ������������� ������ ������� ��������� ���������� ������
     * ��� ������.
     */
    CBlob( unsigned long length );
    /// ���������� ������.
    ~CBlob();

    /**
     * \brief ������� ����� ��������� �������.
     *
     * \param src [in] ������, ����� �������� ���������
     */
    CBlob( const CBlob &src );
    /**
     * \brief �������� �������� ������ � �������.
     *
     * \param src [in] ������, ������� ���������� � �������
     * \return ������ �� ������� ������.
     */
    CBlob& operator=( const CBlob &src );

    /**
     * \brief �������� ������������ (�������������).
     *
     * \param right [in] ������, �������������� � ��������
     * \remarks ��� ���������� ���� �������� � ����� �������� ������� ��������������
     * ������, ������������� �� ��������� �������.
     * \return ������ �� ������� ������.
     */
    CBlob& operator+=( const CBlob &right );
    /**
     * \brief �������� �������� �� ���������.
     *
     * \param src [in] ������ ��� ���������
     * \remarks ������������ ��������� ��������� ��������.
     * \return true � ������ ���������, false � ������ ������.
     */
    bool operator==( const CBlob &src ) const;
    /**
     * \brief �������� �������� �� �����������.
     *
     * \param src [in] ������ ��� ���������
     * \remarks ������������ ��������� ��������� ��������.
     * \return true � ������ �����������, false � ������ ������.
     */
    bool operator!=( const CBlob &src ) const;
    /**
     * \brief �������� ������������������� ��������� (������).
     *
     * \param src [in] ������ ��� ���������
     * \return true � ������ ���� ������� ������ ������, false � ������ ������.
     */
    bool operator<( const CBlob &src ) const;
    /**
     * \brief �������� ������������������� ��������� (������ ��� �����).
     *
     * \param src [in] ������ ��� ���������
     * \return true � ������ ���� ������� ������ ������ ��� �����, false � ������ ������.
     */
    bool operator<=( const CBlob &src ) const;
    /**
     * \brief �������� ������������������� ��������� (������).
     *
     * \param src [in] ������ ��� ���������
     * \return true � ������ ���� ������� ������ ������, false � ������ ������.
     */
    bool operator>( const CBlob &src ) const;
    /**
     * \brief �������� ������������������� ��������� (������ ��� �����).
     *
     * \param src [in] ������ ��� ���������
     * \return true � ������ ���� ������� ������ ������ ��� �����, false � ������ ������.
     */
    bool operator>=( const CBlob &src ) const;

    /**
     * \brief ��������� ������� �������.
     *
     * \param length [in] ����� ����� ������
     * \remarks ���� length ������ ������� �����, �� ������ ������
     * � �������� �� ���� �� ������� ����� �� ������ ������ ��������.
     * ���� length ������ ������� �����, �� ����������� ������ ��
     * �������� �� 0 �� length-1.
     */
    void resize_to( unsigned long length );
    /**
     * \brief �������� ������ ��������.
     *
     * \param right [in] ������ ��� ������
     * \remarks ������� �� ���������� ����������.
     */
    void swap( CBlob &right ) throw();
    /// �������������� ������� ���� ������.
    void reverse();
    /**
     * \brief �������� �������
     * 
     * ������ ��������� � ���������� ������� �����
     */
    void clear();
    /**
     * \brief ��������� ������ � ������
     * 
     * \param ptr [in] ��������� �� ������ ������
     * \param length [in] ����� ������
     */
    void assign(const unsigned char *ptr, unsigned long length );
    void readFromFile( const char *name );
    void writeToFile( const char *name ) const;
    void readFromFile( const wchar_t *name );
    void writeToFile( const wchar_t *name ) const;
    void readFromHexString( const char *str );
    CStringProxy writeToHexString(unsigned long SpaceInterval = 0) const;

    unsigned long cbData() const;
    unsigned char* pbData() const;
private:
    unsigned long m_cbData;
    unsigned char *m_pbData;
};

// VS2008 bug/feature: ������� ���������������� �������� ��������� �������
// (����� - ����������) ������ ���������� ������� ����������������� �������
// �������� ������ (����� - CDllList<>), ����� �� DLL �� ����� ��������������
// ������ ��������� �������.
EXPIMP_CDLLLIST_ITERATORS(CBlob, CPLIB_EXTERN_TEMPLATE, CPLIB_CLASS);

/// ������ �������� CBlob
class CPLIB_CLASS CBlobList: public CDllList<CBlob> {};

} // namespace CryptoPro

#endif // _CPLIB_BLOB_H_INCLUDED
