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
  * \brief Класс блоба.
  */

#ifndef _CPLIB_BLOB_H_INCLUDED
#define _CPLIB_BLOB_H_INCLUDED

#include <algorithm>
#include <list>
#include <cplib/StringProxy.h>

namespace CryptoPro {

    /**
     * \class CBlob Blob.h <cplib/Blob.h>
     * \brief Двоичная последовательность произвольной длины.
     *
     * Класс предназначен для хранения двоичной последовательности.
     * Может использоваться как для хранения закодированных ASN.1 структур,
     * так и для хранения произвольных двоичных данных.
     *
     */
    class CPLIB_CLASS CBlob
    {
    public:
        /// Создает пустой объект
        CBlob();
        /**
         * \brief Создает и инициализирует объект
         *
         * \param ptr [in] указатель на начало данных помещаемых в объект
         * \param length [in] длина данных в байтах
         * \remarks При инициализации объект отводит память под хранимые
         * данные и копирует их туда из указанного в агрументе ptr места.
         */
        CBlob(const unsigned char* ptr, unsigned long length);
        /**
         * \brief Создает объект
         *
         * \param length [in] длина данных в байтах
         * \remarks При инициализации объект отводит указанное количество памяти
         * под данные.
         */
        CBlob(unsigned long length);
        /// Уничтожает объект.
        ~CBlob();

        /**
         * \brief Создает копию заданного объекта.
         *
         * \param src [in] объект, копия которого создается
         */
        CBlob(const CBlob& src);
        /**
         * \brief Копирует заданный объект в текущий.
         *
         * \param src [in] объект, который копируется в текущий
         * \return Ссылка на текущий объект.
         */
        CBlob& operator=(const CBlob& src);

        /**
         * \brief Операция конкатенации (присоединения).
         *
         * \param right [in] объект, присоединяемый к текущему
         * \remarks При выполнении этой операции в конец текущего объекта присоединяются
         * данные, скопированные из заданного объекта.
         * \return Ссылка на текущий объект.
         */
        CBlob& operator+=(const CBlob& right);
        /**
         * \brief Операция проверки на равенство.
         *
         * \param src [in] объект для сравнения
         * \remarks Производится побитовое сравнение объектов.
         * \return true в случае равенства, false в другом случае.
         */
        bool operator==(const CBlob& src) const;
        /**
         * \brief Операция проверки на неравенство.
         *
         * \param src [in] объект для сравнения
         * \remarks Производится побитовое сравнение объектов.
         * \return true в случае неравенства, false в другом случае.
         */
        bool operator!=(const CBlob& src) const;
        /**
         * \brief Операция лексикографического сравнения (меньше).
         *
         * \param src [in] объект для сравнения
         * \return true в случае если текущий объект меньше, false в другом случае.
         */
        bool operator<(const CBlob& src) const;
        /**
         * \brief Операция лексикографического сравнения (меньше или равно).
         *
         * \param src [in] объект для сравнения
         * \return true в случае если текущий объект меньше или равен, false в другом случае.
         */
        bool operator<=(const CBlob& src) const;
        /**
         * \brief Операция лексикографического сравнения (больше).
         *
         * \param src [in] объект для сравнения
         * \return true в случае если текущий объект больше, false в другом случае.
         */
        bool operator>(const CBlob& src) const;
        /**
         * \brief Операция лексикографического сравнения (больше или равно).
         *
         * \param src [in] объект для сравнения
         * \return true в случае если текущий объект больше или равен, false в другом случае.
         */
        bool operator>=(const CBlob& src) const;

        /**
         * \brief Изменение размера объекта.
         *
         * \param length [in] новая длина данных
         * \remarks Если length больше текущей длины, то старые данные
         * в позициях от нуля до текущей длины не меняют своего значения.
         * Если length меньше текущей длины, то сохраняются данные на
         * позициях от 0 до length-1.
         */
        void resize_to(unsigned long length);
        /**
         * \brief Операция обмена объектов.
         *
         * \param right [in] объект для обмена
         * \remarks Функция не генерирует исключений.
         */
        void swap(CBlob& right) throw();
        /// Инвертирование порядка байт данных.
        void reverse();
        /**
         * \brief Очищение объекта
         *
         * Объект очищается и становится нулевой длины
         */
        void clear();
        /**
         * \brief Помещение данных в объект
         *
         * \param ptr [in] указатель на начало данных
         * \param length [in] длина данных
         */
        void assign(const unsigned char* ptr, unsigned long length);
        void readFromFile(const char* name);
        void writeToFile(const char* name) const;
        void readFromFile(const wchar_t* name);
        void writeToFile(const wchar_t* name) const;
        void readFromHexString(const char* str);
        CStringProxy writeToHexString(unsigned long SpaceInterval = 0) const;

        unsigned long cbData() const;
        unsigned char* pbData() const;
    private:
        unsigned long m_cbData;
        unsigned char* m_pbData;
    };

    // VS2008 bug/feature: Экспорт инстанцированных шаблонов вложенных классов
    // (здесь - итераторов) должен предварять экспорт инстанцированного шаблона
    // внешнего класса (здесь - CDllList<>), иначе из DLL не будут экспортированы
    // методы вложенных классов.
    EXPIMP_CDLLLIST_ITERATORS(CBlob, CPLIB_EXTERN_TEMPLATE, CPLIB_CLASS);

    /// Список объектов CBlob
    class CPLIB_CLASS CBlobList : public CDllList<CBlob> {};

} // namespace CryptoPro

#endif // _CPLIB_BLOB_H_INCLUDED
