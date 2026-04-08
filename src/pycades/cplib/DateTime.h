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
  * \brief Класс для работы со временем.
  */

#ifndef _CPLIB_DATETIME_H_INCLUDED
#define _CPLIB_DATETIME_H_INCLUDED

#include <time.h>
#if !defined UNIX
#   include <windows.h>
#endif	/* !UNIX */
#include <cplib/StringProxy.h>

#ifdef UNIX
typedef long long LONGLONG;
#define Int32x32To64( a, b ) (LONGLONG)((LONGLONG)(ULONG)(a) * (ULONG)(b))
#define UInt32x32To64( a, b ) (LONGLONG)((LONGLONG)(ULONG)(a) * (ULONG)(b))
#endif //UNIX

namespace CryptoPro {

    inline ULONG MyInt64Div32(ULONGLONG ll1, ULONG l2) {
        return static_cast<ULONG>(ll1 / l2);
    }

    inline void ULongLongToLowHigh(ULONGLONG ll, DWORD& low, DWORD& high) {
        low = static_cast<DWORD>(ll);
        high = static_cast<DWORD>(ll >> 32);
    }

    inline ULONGLONG ULowHighToLongLong(DWORD low, DWORD high) {
        return static_cast<ULONGLONG>(((static_cast<ULONGLONG>(high)) << 32) + low);
    }

    inline void time_tToFileTime(const time_t& src, DWORD& destHigh, DWORD& destLow) {
        ULONGLONG ll = Int32x32To64(src, 10000000) + 116444736000000000ULL;
        ULongLongToLowHigh(ll, destLow, destHigh);
    }

    inline void FileTimeTotime_t(time_t& dest, const unsigned int& srcHigh, const unsigned int& srcLow) {
        ULONGLONG ll = ULowHighToLongLong(srcLow, srcHigh);
        dest = static_cast<time_t>(MyInt64Div32(ll - 116444736000000000ll, 10000000));
        return;
    }

    inline tm FileTimeToTm(const FILETIME& ftime) {
        tm dest;
        SYSTEMTIME time;
        if (!::FileTimeToSystemTime(&ftime, &time))
            throw;
        dest.tm_year = time.wYear - 1900;
        dest.tm_mon = time.wMonth - 1;
        dest.tm_mday = time.wDay;
        dest.tm_wday = time.wDayOfWeek;
        dest.tm_hour = time.wHour;
        dest.tm_min = time.wMinute;
        dest.tm_sec = time.wSecond;
        dest.tm_yday = 0;
        dest.tm_isdst = 0;
        return dest;
    }

    class CPLIB_CLASS CDateTime;

    /**
     * \class CDateTimeSpan DateTime.h <cplib/DateTime.h>
     * \brief Период времени.
     *
     * Класс хранит период времени с точностью до миксросекунды.
     *
     * \sa CDateTime
     */
    class CPLIB_CLASS
        CDateTimeSpan
    {
    public:
        /// Создает пустой объект
        explicit CDateTimeSpan();
        /**
         * \brief Создает и инициализирует объект
         *
         * \param alya_generalizedTime [in] строковое представление периода времени
         * \remarks Формат строкового представления следующий: "YYYYMMDDhhmmss.ddddddZ"
         * где YYYY - годы, MM - месяцы, DD - дни, hh - часы, mm - минуты, ss - секудны,
         * dddddd - доли секунды (до 6-ти знаков, могут отсутствовать вместе с разделительной
         * точкой. Примеры: "00050600114530Z", "00000000000023.123Z", "00000000000003.123456Z"
         */
        explicit CDateTimeSpan(const char* alya_generalizedTime);
        /**
         * \brief Создает и инициализирует объект
         *
         * \param seconds [in] - количество секунд в периоде времени
         * \param microseconds [in] - количество микросекунд в периоде времени
         */
        explicit CDateTimeSpan(unsigned seconds, unsigned microseconds = 0);
        /**
         * \brief Создает копию заданного объекта.
         *
         * \param src [in] объект, копия которого создается
         */
        CDateTimeSpan(const CDateTimeSpan& src);

        /**
         * \brief Возвращает период времени в строковом формате (ANSI)
         * \sa getGeneralizedTime(), towstring(), CDateTimeSpan()
         */
        CStringProxy tostring() const;
        /**
         * \brief Возвращает период времени в строковом формате (Unicode)
         * \sa getGeneralizedTime(), tostring(), CDateTimeSpan()
         */
        CWStringProxy towstring() const;
        /**
         * \brief Возвращает период времени в строковом формате (ANSI)
         * \sa tostring(), towstring(), CDateTimeSpan()
         */
        CStringProxy getGeneralizedTime() const;

        /**
         * \brief Возвращает младшую часть внутренней переменной
         */
        DWORD getLowPart();

        /**
         * \brief Возвращает старшую часть внутренней переменной
         */
        DWORD getHighPart();

        /**
         * \brief Создает копию заданного объекта.
         *
         * \param src [in] объект, копия которого создается
         */
        CDateTimeSpan& operator=(const CDateTimeSpan& src);
        /**
         * \brief Операция обмена объектов.
         *
         * \param src [in] объект для обмена
         * \remarks Функция не генерирует исключений.
         */
        void swap(CDateTimeSpan& src) throw();

        CPLIB_API friend bool operator==(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend bool operator!=(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend bool operator<=(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend bool operator>=(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend bool operator<(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend bool operator>(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTime& operator +=(CDateTime& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTime& operator -=(CDateTime& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTimeSpan& operator +=(CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTimeSpan& operator -=(CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTimeSpan operator -(const CDateTime& lhs, const CDateTime& rhs);

        CPLIB_API friend CDateTimeSpan& operator *=(CDateTimeSpan& lhs, unsigned rhs);
        CPLIB_API friend CDateTimeSpan& operator /=(CDateTimeSpan& lhs, unsigned rhs);
        CPLIB_API friend CDateTimeSpan& operator %=(CDateTimeSpan& lhs, unsigned rhs);

        CPLIB_API friend CDateTimeSpan operator *(const CDateTimeSpan& lhs, unsigned rhs);
        CPLIB_API friend CDateTimeSpan operator /(const CDateTimeSpan& lhs, unsigned rhs);
        CPLIB_API friend CDateTimeSpan operator %(const CDateTimeSpan& lhs, unsigned rhs);

        CPLIB_API friend unsigned operator / (const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTimeSpan operator % (const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);

        static const CDateTimeSpan& OneYear();
        static const CDateTimeSpan& OneMonth();
        static const CDateTimeSpan& OneDay();
        static const CDateTimeSpan& OneHour();
        static const CDateTimeSpan& OneMinute();
        static const CDateTimeSpan& OneSecond();
        static const CDateTimeSpan& OneMillisecond();

    private:
        /// Период один год (365 дней)
        static const CDateTimeSpan oneYear;
        /// Период один месяц (30 дней)
        static const CDateTimeSpan oneMonth;
        /// Период один день
        static const CDateTimeSpan oneDay;
        /// Период один час
        static const CDateTimeSpan oneHour;
        /// Период одна минута
        static const CDateTimeSpan oneMinute;
        /// Период одна секунда
        static const CDateTimeSpan oneSecond;
        /// Период одна миллисекунда
        static const CDateTimeSpan oneMillisecond;

        DWORD high_;
        DWORD low_;
    };

    /**
     * \class CDateTime DateTime.h <cplib/DateTime.h>
     * \brief Время.
     *
     * Класс хранит значение времени с точностью до миксросекунды.
     *
     * \sa CDateTimeSpan
     */
    class CPLIB_CLASS
        CDateTime
    {
    public:
        /**
        * \brief Создает и инициализирует объект
        *
        * \param time [in] - время в формате __time64_t
        * \param micro [in] - количество микросекунд
        */
        explicit CDateTime(long long time = 0, unsigned int micro = 0);
        /**
         * \brief Создает и инициализирует объект
         *
         * \param generalizedTime [in] строковое представление периода времени
         * \remarks Формат строкового представления следующий: "YYYYMMDDhhmmss.ddddddZ"
         * где YYYY - годы, MM - месяцы, DD - дни, hh - часы, mm - минуты, ss - секудны,
         * dddddd - доли секунды (до 6-ти знаков, могут отсутствовать вместе с разделительной
         * точкой. Примеры: "20041105114530Z", "19940821101532.123Z", "19940821101532.123456Z"
         */
        explicit CDateTime(const char* generalizedTime);
        /**
     * \brief Создает и инициализирует объект
     *
     * \param time [in] - время в формате __time32_t
     * \param micro [in] - количество микросекунд
     */
        CDateTime(long time, unsigned int micro);
        /**
         * \brief Создает и инициализирует объект
         *
         * \param filetime [in] время в формате FILETIME
         */
        CDateTime(FILETIME filetime);
        /**
         * \brief Создает и инициализирует объект
         *
         * \param systemtime [in] время в формате SYSTEMTIME
         */
        CDateTime(SYSTEMTIME systemtime);
        /**
        * \brief Создает и инициализирует объект
        *
        * \param year [in] год
        * \param month [in] месяц
        * \param day [in] день
        * \param hour [in] час
        * \param minute [in] минуты
        * \param second [in] секунды
        * \param milli [in] миллисекунды
        * \param micro [in] микросекунды
        */
        CDateTime(
            unsigned int year,
            unsigned int month,
            unsigned int day,
            unsigned int hour = 0,
            unsigned int minute = 0,
            unsigned int second = 0,
            unsigned int milli = 0,
            unsigned int micro = 0);
        /**
         * \brief Создает копию заданного объекта.
         *
         * \param time [in] объект, копия которого создается
         */
        CDateTime(const CDateTime& time);
        /**
         * \brief Создает копию заданного объекта.
         *
         * \param src [in] объект, копия которого создается
         */
        CDateTime& operator=(const CDateTime& src);
        /**
         * \brief Операция обмена объектов.
         *
         * \param src [in] объект для обмена
         * \remarks Функция не генерирует исключений.
         */
        void swap(CDateTime& src) throw();

        /// Возвращает год
        unsigned int year() const;
        /// Возвращает месяц
        unsigned int month() const;
        /// Возвращает день
        unsigned int day() const;
        /// Возвращает час
        unsigned int hour() const;
        /// Возвращает минуту
        unsigned int minute() const;
        /// Возвращает секунды
        unsigned int second() const;
        /// Возвращает миллисекунды
        unsigned int millisecond() const;
        /// Возвращает микросекунды
        unsigned int microsecond() const;

        /**
         * \brief Возвращает время в строковом формате (ANSI)
         * \sa getTime(), getFileTime(), getSystemTime(), tostring(), towstring(), CDateTimeSpan
         */
        CStringProxy getGeneralizedTime() const;
        CStringProxy getGeneralizedTimeTrimMicroseconds() const;
        /**
         * \brief Возвращает время в формате time_t
         * \sa getGeneralizedTime(), getFileTime(), getSystemTime(), tostring(), towstring(), CDateTimeSpan
         */
        time_t getTime() const;
        /**
         * \brief Возвращает время в формате FILETIME
         * \sa getGeneralizedTime(), getTime(), getSystemTime(), tostring(), towstring(), CDateTimeSpan
         */
        FILETIME getFileTime() const;
        /**
         * \brief Возвращает время в формате SYSTEMTIME
         * \sa getGeneralizedTime(), getTime(), getFileTime(), tostring(), towstring(), CDateTimeSpan
         */
        SYSTEMTIME getSystemTime() const;
        /**
         * \brief Возвращает время в локализованном строковом формате (ANSI)
         * \sa getGeneralizedTime(), getTime(), getFileTime(), getSystemTime(), towstring(), CDateTimeSpan
         */
        CStringProxy tostring() const;
        /**
         * \brief Возвращает время в локализованном строковом формате (Unicode)
         * \sa getGeneralizedTime(), getTime(), getFileTime(), getSystemTime(), tostring(), CDateTimeSpan
         */
        CWStringProxy towstring() const;
        /**
         * \brief Возвращает время, преобразованное к локальному представлению
         * \sa localToUtc()
         */
        CDateTime utcToLocal() const;
        /**
         * \brief Возвращает время, преобразованное к представлению в системе универсального координированного времени (UTC)
         * \sa utcToLocal()
         */
        CDateTime localToUtc() const;

        /// Возвращает объект с текущим значение времени с точностью до микросекунд в системе универсального координированного времени (UTC)
        static CDateTime Now();

        /// Возвращает объект с текущим значение времени с точностью до микросекунд в системе универсального координированного времени (UTC)
        static CDateTime GetCurrentTime() { return Now(); }

        CPLIB_API friend bool operator==(const CDateTime& lhs, const CDateTime& rhs);
        CPLIB_API friend bool operator!=(const CDateTime& lhs, const CDateTime& rhs);
        CPLIB_API friend bool operator<=(const CDateTime& lhs, const CDateTime& rhs);
        CPLIB_API friend bool operator>=(const CDateTime& lhs, const CDateTime& rhs);
        CPLIB_API friend bool operator<(const CDateTime& lhs, const CDateTime& rhs);
        CPLIB_API friend bool operator>(const CDateTime& lhs, const CDateTime& rhs);
        CPLIB_API friend CDateTime& operator +=(CDateTime& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTime& operator -=(CDateTime& lhs, const CDateTimeSpan& rhs);
        CPLIB_API friend CDateTimeSpan operator -(const CDateTime& lhs, const CDateTime& rhs);

#ifdef UNIX
        CDateTime(timeval tval);
        timeval getTimeval() const;
#endif // UNIX
    private:
        DWORD high_;
        DWORD low_;
    };

    /// Операция проверки на равенство
    CPLIB_API bool operator==(const CDateTime& lhs, const CDateTime& rhs);
    /// Операция проверки на неравенство
    CPLIB_API bool operator!=(const CDateTime& lhs, const CDateTime& rhs);
    /// Операция сравнения (меньше или равно)
    CPLIB_API bool operator<=(const CDateTime& lhs, const CDateTime& rhs);
    /// Операция сравнения (больше или равно)
    CPLIB_API bool operator>=(const CDateTime& lhs, const CDateTime& rhs);
    /// Операция сравнения (меньше)
    CPLIB_API bool operator<(const CDateTime& lhs, const CDateTime& rhs);
    /// Операция сравнения (больше)
    CPLIB_API bool operator>(const CDateTime& lhs, const CDateTime& rhs);

    /// Операция проверки на равенство
    CPLIB_API bool operator==(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция проверки на неравенство
    CPLIB_API bool operator!=(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция сравнения (меньше или равно)
    CPLIB_API bool operator<=(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция сравнения (больше или равно)
    CPLIB_API bool operator>=(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция сравнения (меньше)
    CPLIB_API bool operator<(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция сравнения (больше)
    CPLIB_API bool operator>(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция прибавления периода ко времени
    CPLIB_API CDateTime& operator +=(CDateTime& lhs, const CDateTimeSpan& rhs);
    /// Операция вычитания периода из времени
    CPLIB_API CDateTime& operator -=(CDateTime& lhs, const CDateTimeSpan& rhs);

    /// Операция прибавления периода к периоду
    CPLIB_API CDateTimeSpan& operator +=(CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /**
     * \brief Операция вычитания периода из периода
     * \remark Период времени не может буть отрицательным. Если в результате
     * вычитания получается отрицательный период, генерируется исключение.
     */
    CPLIB_API CDateTimeSpan& operator -=(CDateTimeSpan& lhs, const CDateTimeSpan& rhs);

    /// Операция умножения периода на число
    CPLIB_API CDateTimeSpan& operator *=(CDateTimeSpan& lhs, unsigned rhs);
    /// Операция деления периода на число
    CPLIB_API CDateTimeSpan& operator /=(CDateTimeSpan& lhs, unsigned rhs);
    /// Операция получения остатка от деления периода на число
    CPLIB_API CDateTimeSpan& operator %=(CDateTimeSpan& lhs, unsigned rhs);

    /// Операция умножения периода на число
    CPLIB_API CDateTimeSpan operator *(const CDateTimeSpan& lhs, unsigned rhs);
    /// Операция деления периода на число
    CPLIB_API CDateTimeSpan operator /(const CDateTimeSpan& lhs, unsigned rhs);
    /// Операция получения остатка от деления периода на число
    CPLIB_API CDateTimeSpan operator %(const CDateTimeSpan& lhs, unsigned rhs);

    /// Операция деления периода на период
    CPLIB_API unsigned operator / (const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция получения остатка от деления периода на период
    CPLIB_API CDateTimeSpan operator % (const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);

    /**
     * \brief Операция вычитания периода из периода
     * \remark Период времени не может буть отрицательным. Если в результате
     * вычитания получается отрицательный период, генерируется исключение.
     */
    CPLIB_API CDateTimeSpan operator -(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /**
     * \brief Операция вычитания времени из времени
     * \remark Период времени не может буть отрицательным. При вычитании
     * более позднего момента времени из более раннего генерируется исключение
     */
    CPLIB_API CDateTimeSpan operator -(const CDateTime& lhs, const CDateTime& rhs);
    /// Операция вычитания периода из даты
    CPLIB_API CDateTime operator -(const CDateTime& lhs, const CDateTimeSpan& rhs);

    /// Операция прибавления периода к периоду
    CPLIB_API CDateTimeSpan operator +(const CDateTimeSpan& lhs, const CDateTimeSpan& rhs);
    /// Операция прибавления периода ко времени
    CPLIB_API CDateTime operator +(const CDateTime& lhs, const CDateTimeSpan& rhs);

    /**
    * \brief Функция прибавления к дате заданного отрезка времени
    *
    * \param intervalUnit [in] единицы измерения в которых задаётся интервал, значение
    *        параметра может быть равным:
    *	 - "s" - секунды;
    *	 - "n" - минуты;
    *	 - "h" - часы;
    *	 - "d" - дни;
    *	 - "w" - недели;
    *	 - "m" - месяцы;
    *	 - "y" - годы.
    * \param interval [in] размер прибавляемого интервала
    * \param value [in] дата, к которой прибавляется интервал
    *
    * \return Новое значение даты.
    */
    CPLIB_API CDateTime DateAddA(const char* intervalUnit,
        int interval, const CDateTime& value);

    /**
    * \brief Функция прибавления к дате заданного отрезка времени
    *
    * \param intervalUnit [in] единицы измерения в которых задаётся интервал, значение
    *        параметра может быть равным:
    *	 - "s" - секунды;
    *	 - "n" - минуты;
    *	 - "h" - часы;
    *	 - "d" - дни;
    *	 - "w" - недели;
    *	 - "m" - месяцы;
    *	 - "y" - годы.
    * \param interval [in] размер прибавляемого интервала
    * \param value [in] дата, к которой прибавляется интервал
    *
    * \return Новое значение даты.
    */
    CPLIB_API CDateTime DateAddW(const wchar_t* intervalUnit,
        int interval, const CDateTime& value);

    /**
     * \brief Функция возвращает объект со временем (UTC), извлеченным из строки, представленной в формате xsd:dateTime.
     *
     * \param lexicalDateTime [in] строка в формате xsd:dateTime
     * \sa toXsdDateTimeString()
     */
    CPLIB_API CDateTime fromXsdDateTimeString(const char* lexicalDateTime);
    /**
     * \brief Функция возвращает строку в формате xsd:dateTime со значением переданного времени с точностью до миллисекунд в системе универсального координированного времени (UTC) или пустую строку в случае ошибки.
     *
     * \param dateTime [in] время
     * \sa fromXsdDateTimeString()
     */
    CPLIB_API CStringProxy toXsdDateTimeString(const CDateTime& dateTime);

#ifdef UNICODE
#define DateAdd DateAddW
#else
#define DateAdd DateAddA
#endif

} // namespace CryptoPro

#endif //_CPLIB_DATETIME_H_INCLUDED
