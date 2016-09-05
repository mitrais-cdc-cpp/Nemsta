// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef MONITOR_HISTORY_ODB_H
#define MONITOR_HISTORY_ODB_H

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
#include <odb/boost/optional/wrapper-traits.hxx>
#include <odb/boost/unordered/container-traits.hxx>
#include <odb/boost/date-time/mysql/gregorian-traits.hxx>
#include <odb/boost/date-time/mysql/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/mysql/uuid-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "MonitorHistory.hpp"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // MonitorHistory
  //
  template <>
  struct class_traits< ::MonitorHistory >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::MonitorHistory >
  {
    public:
    typedef ::MonitorHistory object_type;
    typedef ::std::shared_ptr< ::MonitorHistory > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // MonitorHistory
  //
  template <typename A>
  struct query_columns< ::MonitorHistory, id_mysql, A >
  {
    // monitorHistoryId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    monitorHistoryId_type_;

    static const monitorHistoryId_type_ monitorHistoryId;

    // lastUpdate
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long long unsigned int,
        mysql::id_longlong >::query_type,
      mysql::id_longlong >
    lastUpdate_type_;

    static const lastUpdate_type_ lastUpdate;

    // note
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    note_type_;

    static const note_type_ note;
  };

  template <typename A>
  const typename query_columns< ::MonitorHistory, id_mysql, A >::monitorHistoryId_type_
  query_columns< ::MonitorHistory, id_mysql, A >::
  monitorHistoryId (A::table_name, "`monitorHistoryId`", 0);

  template <typename A>
  const typename query_columns< ::MonitorHistory, id_mysql, A >::lastUpdate_type_
  query_columns< ::MonitorHistory, id_mysql, A >::
  lastUpdate (A::table_name, "`lastUpdate`", 0);

  template <typename A>
  const typename query_columns< ::MonitorHistory, id_mysql, A >::note_type_
  query_columns< ::MonitorHistory, id_mysql, A >::
  note (A::table_name, "`note`", 0);

  template <typename A>
  struct pointer_query_columns< ::MonitorHistory, id_mysql, A >:
    query_columns< ::MonitorHistory, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::MonitorHistory, id_mysql >:
    public access::object_traits< ::MonitorHistory >
  {
    public:
    struct id_image_type
    {
      unsigned long long id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // monitorHistoryId_
      //
      unsigned long long monitorHistoryId_value;
      my_bool monitorHistoryId_null;

      // lastUpdate_
      //
      long long lastUpdate_value;
      my_bool lastUpdate_null;

      // note_
      //
      details::buffer note_value;
      unsigned long note_size;
      my_bool note_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::MonitorHistory, id_common >:
    public access::object_traits_impl< ::MonitorHistory, id_mysql >
  {
  };

  // MonitorHistory
  //
}

#include "MonitorHistory_odb_inline.h"

#include <odb/post.hxx>

#endif // MONITOR_HISTORY_ODB_H
