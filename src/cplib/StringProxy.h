/*
 * Copyright (c) 2026, компания КриптоПро
 *
 * Разрешается повторное распространение и использование как в виде исходного
 * кода, так и в двоичной форме, с изменениями или без, при соблюдении
 * следующих условий:
 *
 * 1) При повторном распространении исходного кода должно оставаться
 *    указанное выше уведомление об авторском праве, этот список условий
 *    и последующий отказ от гарантий.
 *
 * 2) При повторном распространении двоичного кода должна сохраняться
 *    указанная выше информация об авторском праве, этот список условий
 *    и последующий отказ от гарантий в документации и/или в других материалах,
 *    поставляемых при распространении.
 *
 * ЭТА ПРОГРАММА ПРЕДОСТАВЛЕНА БЕСПЛАТНО ВЛАДЕЛЬЦАМИ АВТОРСКИХ ПРАВ И/ИЛИ
 * ДРУГИМИ СТОРОНАМИ "КАК ОНА ЕСТЬ" БЕЗ КАКОГО-ЛИБО ВИДА ГАРАНТИЙ, ВЫРАЖЕННЫХ
 * ЯВНО ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ, ПОДРАЗУМЕВАЕМЫЕ
 * ГАРАНТИИ КОММЕРЧЕСКОЙ ЦЕННОСТИ И ПРИГОДНОСТИ ДЛЯ КОНКРЕТНОЙ ЦЕЛИ. НИ В КОЕМ
 * СЛУЧАЕ, ЕСЛИ НЕ ТРЕБУЕТСЯ СООТВЕТСТВУЮЩИМ ЗАКОНОМ, ИЛИ НЕ УСТАНОВЛЕНО В
 * УСТНОЙ ФОРМЕ, НИ ОДИН ВЛАДЕЛЕЦ АВТОРСКИХ ПРАВ И НИ ОДНО ДРУГОЕ ЛИЦО, КОТОРОЕ
 * МОЖЕТ ИЗМЕНЯТЬ И/ИЛИ ПОВТОРНО РАСПРОСТРАНЯТЬ ПРОГРАММУ, КАК БЫЛО СКАЗАНО
 * ВЫШЕ, НЕ НЕСЁТ ОТВЕТСТВЕННОСТИ, ВКЛЮЧАЯ ЛЮБЫЕ ОБЩИЕ, СЛУЧАЙНЫЕ, СПЕЦИАЛЬНЫЕ
 * ИЛИ ПОСЛЕДОВАВШИЕ УБЫТКИ, ВСЛЕДСТВИЕ ИСПОЛЬЗОВАНИЯ ИЛИ НЕВОЗМОЖНОСТИ
 * ИСПОЛЬЗОВАНИЯ ПРОГРАММЫ (ВКЛЮЧАЯ, НО НЕ ОГРАНИЧИВАЯСЬ ПОТЕРЕЙ ДАННЫХ,
 * ИЛИ ДАННЫМИ, СТАВШИМИ НЕПРАВИЛЬНЫМИ, ИЛИ ПОТЕРЯМИ, ПРИНЕСЕННЫМИ ИЗ-ЗА ВАС ИЛИ
 * ТРЕТЬИХ ЛИЦ, ИЛИ ОТКАЗОМ ПРОГРАММЫ РАБОТАТЬ СОВМЕСТНО С ДРУГИМИ ПРОГРАММАМИ),
 * ДАЖЕ ЕСЛИ ТАКОЙ ВЛАДЕЛЕЦ ИЛИ ДРУГОЕ ЛИЦО БЫЛИ ИЗВЕЩЕНЫ О ВОЗМОЖНОСТИ
 * ТАКИХ УБЫТКОВ.
 *
 * Copyright (c) 2026, CryptoPro Company All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1) Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2) Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

 /*!
  * \file $RCSfile$
  * \version $Revision$
  * \date $Date::                           $
  * \author $Author$
  *
  * \brief Прокси-объекты для строк
  */

#ifndef _STRINGPROXY_H_INCLUDED
#define _STRINGPROXY_H_INCLUDED

#if !defined CPLIB_DLL_DEFINES
#   define CPLIB_DLL_DEFINES
#   if defined _WIN32 && !defined CRYPTCP && !defined CPLIB_STATIC
#	if defined CPLIB_DLL
#	    define CPLIB_CLASS __declspec(dllexport)
#	    define CPLIB_API __declspec(dllexport)
#	    define CPLIB_DATA __declspec(dllexport)
#	    define CPLIB_EXTERN_TEMPLATE
#	else // defined CPLIB_DLL
#	    define CPLIB_CLASS __declspec(dllimport)
#	    define CPLIB_API __declspec(dllimport)
#	    define CPLIB_DATA __declspec(dllimport)
#	    define CPLIB_EXTERN_TEMPLATE extern
#	    ifndef CP_IGNORE_PRAGMA_MANIFEST
#	        include "cplib_assembly.h"
#	        ifdef _WIN64
#	            pragma comment(linker,"/manifestdependency:\"type='win32' " \
 	            "name='" CPLIB_ASSEMBLY_NAME_X64 "' " \
 	            "version='" CPLIB_ASSEMBLY_VERSION_X64 "' " \
 	            "processorArchitecture='amd64' " \
 	            "language='*' " \
 	            "publicKeyToken='" CPLIB_ASSEMBLY_PUBLICKEYTOKEN_X64 "'\"")
#	        else
#	            pragma comment(linker,"/manifestdependency:\"type='win32' " \
 	            "name='" CPLIB_ASSEMBLY_NAME_X86 "' " \
 	            "version='" CPLIB_ASSEMBLY_VERSION_X86 "' " \
 	            "processorArchitecture='x86' " \
 	            "language='*' " \
 	            "publicKeyToken='" CPLIB_ASSEMBLY_PUBLICKEYTOKEN_X86 "'\"")
# 	        endif
#	    endif
#	endif // !defined CPLIB_DLL
#   else // defined _WIN32 && !defined CRYPTCP && !defined CPLIB_STATIC
#	define CPLIB_CLASS
#	define CPLIB_API
#	define CPLIB_DATA
#	define CPLIB_EXTERN_TEMPLATE
#       define NO_EXPIMP_CDLLLIST_ITERATORS
#   endif // !defined _WIN32 || defined CRYPTCP || defined CPLIB_STATIC
#endif // !defined CPLIB_DLL_DEFINES

#include <string>
#ifndef wstring
namespace std {
    typedef basic_string<wchar_t> wstring;
}
#endif //wstring

#include <cpstldll.h>

namespace CryptoPro {

    /**
     * \class CStringProxy StringProxy.h <cplib/StringProxy.h>
     * \brief Объект-посредник для строк.
     *
     * В объектах этого класса функции входящие в пространство
     * имен CryptoPro возвращают ANSI строки. Цель этого класса - обеспечить
     * коректное освобождение памяти, отведенной под строку (память отводится внутри
     * динамической библиотеки, и освобождаться должна там же).
     *
     * При обычном использовании функций из пространства имен CryptoPro
     * нет необходимости непосредственно использовать этот класс. В классе
     * предоставлена функция \link CryptoPro::CStringProxy::c_str c_str() \endlink,
     * возвращающая указатель на c-строку ( по аналогии с std::string ).
     * Пример правильного использования функции, возвращающей объект
     * класса CStringProxy:
     *
     * \code
     *
     * CStringProxy f();
     *
     * std::string s = f().c_str();
     * CString atls = f().c_str();
     *
     * \endcode
     *
     * Некорректно использовать этот класс следующим образом:
     *
     * \code
     * const char* s = f().c_str();
     * \endcode
     *
     * Содержимое памяти на которое указывает s будет неопределено, поскольку
     * f() возвращает временный объект, который уничтожается после возврата из
     * функции. Следующий код корректен:
     *
     * \code
     *
     * // получение длины
     * size_t len = strlen(f());
     *
     * // отведение памяти под строку
     * const char* s = (char*)malloc(len+1);
     * if(!s)
     *     error("not enough memory");
     *
     * // получение строки и копирование в отведенную память
     * strncpy(s,f(),len+1);
     *
     * \endcode
     *
     * \sa CWStringProxy
     */
    class CPLIB_CLASS
        CStringProxy
    {
    public:
        /**
         * \brief Создает и инициализирует объект
         *
         * \param str [in] указатель на массив символов
         */
        CStringProxy(const char* str = "");
        /**
         * \brief Создает копию заданного объекта.
         *
         * \param src [in] объект, копия которого создается
         */
        CStringProxy(const CStringProxy& src);
        /**
         * \brief Копирует заданный объект в текущий.
         *
         * \param src [in] объект, который копируется в текущий
         * \return Ссылка на текцщий объект.
         */
        CStringProxy& operator=(const CStringProxy& src);
        /// Уничтожает объект.
        ~CStringProxy();

        /// Приводит объект к типу const char*
        const char* c_str() const;
    private:
#ifndef UNIX
#pragma warning(push)
#pragma warning(disable: 4251)
#endif
        std::string* m_pValue;
#ifndef UNIX
#pragma warning(pop)
#endif
    };

    /**
     * \class CWStringProxy StringProxy.h <cplib/StringProxy.h>
     * \brief Объект-посредник для строк.
     *
     * В объектах этого класса функции входящие в пространство
     * имен CryptoPro возвращают UNICODE строки. Цель этого класса - обеспечить
     * коректное освобождение памяти, отведенной под строку (память отводится внутри
     * динамической библиотеки, и освобождаться должна там же).
     *
     * При обычном использовании функций из пространства имен CryptoPro
     * нет необходимости непосредственно использовать этот класс. В классе
     * предоставлена функция \link CryptoPro::CStringProxy::c_str c_str() \endlink,
     * возвращающая указатель на c-строку ( по аналогии с std::wstring ).
     * Пример правильного использования функции, возвращающей объект
     * класса CWStringProxy:
     *
     * \code
     *
     * CWStringProxy f();
     *
     * std::wstring s = f().c_str();
     * CString atls = f().c_str();
     *
     * \endcode
     *
     * Некорректно использовать этот класс следующим образом:
     *
     * \code
     * const wchar_t* s = f().c_str();
     * \endcode
     *
     * Содержимое памяти на которое указывает s будет неопределено, поскольку
     * f() возвращает временный объект, который уничтожается после возврата из
     * функции. Следующий код корректен:
     *
     * \code
     *
     * // получение длины
     * size_t len = wcslen(f());
     *
     * // отведение памяти под строку
     * const char* s = (char*)malloc((len+1)*sizeof(wchar_t));
     * if(!s)
     *     error("not enough memory");
     *
     * // получение строки и копирование в отведенную память
     * wcsncpy(s,f(),len+1);
     *
     * \endcode
     *
     * \sa CStringProxy
     */
    class CPLIB_CLASS
        CWStringProxy
    {
    public:
        /**
         * \brief Создает и инициализирует объект
         *
         * \param str [in] указатель на массив символов
         */
        CWStringProxy(const wchar_t* str = L"");
        /**
         * \brief Создает копию заданного объекта.
         *
         * \param src [in] объект, копия которого создается
         */
        CWStringProxy(const CWStringProxy& src);
        /**
         * \brief Копирует заданный объект в текущий.
         *
         * \param src [in] объект, который копируется в текущий
         * \return Ссылка на текцщий объект.
         */
        CWStringProxy& operator=(const CWStringProxy& src);
        /// Уничтожает объект.
        ~CWStringProxy();

        /// Приводит объект к типу const wchar_t*
        const wchar_t* c_str() const;
    private:
#ifndef UNIX
#pragma warning(push)
#pragma warning(disable: 4251)
#endif
        std::wstring* m_pValue;
#ifndef UNIX
#pragma warning(pop)
#endif
    };

    // VS2008 bug/feature: Экспорт инстанцированных шаблонов вложенных классов
    // (здесь - итераторов) должен предварять экспорт инстанцированного шаблона
    // внешнего класса (здесь - CDllList<>), иначе из DLL не будут экспортированы
    // методы вложенных классов.
    EXPIMP_CDLLLIST_ITERATORS(CStringProxy, CPLIB_EXTERN_TEMPLATE, CPLIB_CLASS);

    /// Список объектов CStringProxy
    class CPLIB_CLASS CStringList : public CDllList<CStringProxy> {};

    // VS2008 bug/feature: Экспорт инстанцированных шаблонов вложенных классов
    // (здесь - итераторов) должен предварять экспорт инстанцированного шаблона
    // внешнего класса (здесь - CDllList<>), иначе из DLL не будут экспортированы
    // методы вложенных классов.
    EXPIMP_CDLLLIST_ITERATORS(CWStringProxy, CPLIB_EXTERN_TEMPLATE, CPLIB_CLASS);

    /// Список объектов CWStringProxy
    class CPLIB_CLASS CWStringList : public CDllList<CWStringProxy> {};

} // namespace CryptoPro

#endif // _STRINGPROXY_H_INCLUDED
