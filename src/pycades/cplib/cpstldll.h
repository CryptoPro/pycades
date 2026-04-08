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
  * \brief Обертки для stl классов, позволяющие их экспортировать в dll.
  */

#ifndef _CPSTLDLL_H_INCLUDED
#define _CPSTLDLL_H_INCLUDED

#include <list>

#if defined UNIX
#   define CDllList std::list
#   define EXPIMP_CDLLLIST_ITERATORS(...)
#else // !defined UNIX

#ifdef NO_EXPIMP_CDLLLIST_ITERATORS
#   define EXPIMP_CDLLLIST_ITERATORS(...)
#else
#   define EXPIMP_CDLLLIST_ITERATORS(Type, Extern, Declspec) \
	__pragma(warning(push)); \
	__pragma(warning(disable: 4231)); \
	Extern template class Declspec CDllList<Type>::_Const_iterator; \
	Extern template class Declspec CDllList<Type>::_Iterator; \
	__pragma(warning(pop));
#endif

namespace CryptoPro {

    /**
     * \class CDllList cpstldll.h <cpstldll.h>
     * \brief Класс списка аналогичный по интерфейсу классу std::list из библиотеки
     * стандартных шаблонов.
     */
    template<class _Ty>
    class CDllList
    {
        typedef typename std::list<_Ty> stlContainer;
        typedef CDllList<_Ty> _Myt;
        typedef typename stlContainer::pointer _Tptr;
        typedef typename stlContainer::reference _Reft;
#ifdef _STL70_
        typedef typename stlContainer::iterator cont_const_iterator;
#else
        typedef typename stlContainer::const_iterator cont_const_iterator;
#endif
        typedef typename stlContainer::iterator cont_iterator;
    public:
        typedef typename stlContainer::allocator_type allocator_type;
        typedef typename stlContainer::size_type size_type;
        typedef typename stlContainer::difference_type difference_type;
        typedef typename stlContainer::pointer pointer;
        typedef typename stlContainer::const_pointer const_pointer;
        typedef typename stlContainer::reference reference;
        typedef typename stlContainer::const_reference const_reference;
        typedef typename stlContainer::value_type value_type;
        typedef typename stlContainer::const_reverse_iterator const_reverse_iterator;
        typedef typename stlContainer::reverse_iterator reverse_iterator;

        class _Const_iterator
#if defined(_MSC_VER) && (_MSC_VER >= 1500) && (_MSC_VER < 1600) && !defined ( _STL70_ )
            // Чтобы VS2008 считала итератор за checked
            : public std::_Iterator_base_universal
#endif // defined(_MSC_VER) && (_MSC_VER >= 1500) && (_MSC_VER < 1700)
        {
        friend CDllList;

        cont_const_iterator* pImpl_;

        _Const_iterator(const cont_const_iterator it);

        public:
    #if defined(_MSC_VER) && (_MSC_VER >= 1500) && (_MSC_VER < 1600)
        typedef std::_Range_checked_iterator_tag _Checked_iterator_category;
    #endif //defined(_MSC_VER) && (_MSC_VER >= 1500) && (_MSC_VER < 1700)

        typedef std::bidirectional_iterator_tag iterator_category;
        typedef _Ty value_type;
        typedef typename stlContainer::difference_type difference_type;
        typedef typename stlContainer::const_pointer pointer;
        typedef typename stlContainer::const_reference reference;

        _Const_iterator();
        ~_Const_iterator();

        _Const_iterator(const _Const_iterator& _Right);
        _Const_iterator& operator=(const _Const_iterator& _Right);

        const_reference operator*() const;
        const_pointer operator->() const;
        _Const_iterator& operator++();
        _Const_iterator operator++(int);
        _Const_iterator& operator--();
        _Const_iterator operator--(int);
        bool operator==(const _Const_iterator& _Right) const;
        bool operator!=(const _Const_iterator& _Right) const;
        };

        class _Iterator : public _Const_iterator
        {
            friend CDllList;

            _Iterator(const cont_iterator it);

        public:
            _Iterator();

            _Reft operator*() const;
            _Tptr operator->() const;
            _Iterator& operator++();
            _Iterator operator++(int);
            _Iterator& operator--();
            _Iterator operator--(int);
        };

        typedef _Const_iterator const_iterator;
        typedef _Iterator iterator;

        CDllList();
        CDllList(const _Myt& _Right);
        ~CDllList();

        const_iterator begin() const;
        const_iterator end() const;
        iterator begin();
        iterator end();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        _Myt& operator=(const _Myt& _Right);
        void resize(size_type _Newsize);
        void resize(size_type _Newsize, _Ty _Val);
        size_type size() const;
        size_type max_size() const;
        bool empty() const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        void push_front(const _Ty& _Val);
        void push_back(const _Ty& _Val);
        void pop_front();
        void pop_back();
        void assign(size_type _Count, const _Ty& _Val);
        iterator insert(iterator _Where, const _Ty& _Val);
        void insert(iterator _Where, iterator _First, iterator _Last);
        void insert(iterator _Where, size_type _Count, const _Ty& _Val);
        iterator erase(iterator _Where);
        iterator erase(iterator _First, iterator _Last);
        void clear();
        void swap(_Myt& _Right);
        //    void sort();
        //    void reverse();
    protected:
        void* impl();
        const void* impl() const;
    private:
        void* pImpl_;
    };

} // namespace CryptoPro

#endif // !defined UNIX

#endif // _CPSTLDLL_H_INCLUDED
