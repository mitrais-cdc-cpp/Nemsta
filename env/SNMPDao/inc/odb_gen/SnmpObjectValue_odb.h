// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef SNMP_OBJECT_VALUE_ODB_H
#define SNMP_OBJECT_VALUE_ODB_H

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

#include "SnmpObjectValue.hpp"

#include "MonitorHistory_odb.h"
#include "SnmpObject_odb.h"
#include "SnmpObjectType_odb.h"

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
  // SnmpObjectValue
  //
  template <>
  struct class_traits< ::SnmpObjectValue >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::SnmpObjectValue >
  {
    public:
    typedef ::SnmpObjectValue object_type;
    typedef ::std::shared_ptr< ::SnmpObjectValue > pointer_type;
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
  // SnmpObjectValue
  //
  template <typename A>
  struct pointer_query_columns< ::SnmpObjectValue, id_mysql, A >
  {
    // snmpObjectValueId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectValueId_type_;

    static const snmpObjectValueId_type_ snmpObjectValueId;

    // value
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    value_type_;

    static const value_type_ value;

    // snmpObjectFk
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectFk_type_;

    static const snmpObjectFk_type_ snmpObjectFk;

    // snmpObjectTypeFk
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectTypeFk_type_;

    static const snmpObjectTypeFk_type_ snmpObjectTypeFk;

    // monitorHistoryFk
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    monitorHistoryFk_type_;

    static const monitorHistoryFk_type_ monitorHistoryFk;
  };

  template <typename A>
  const typename pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::snmpObjectValueId_type_
  pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::
  snmpObjectValueId (A::table_name, "`snmpObjectValueId`", 0);

  template <typename A>
  const typename pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::value_type_
  pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::
  value (A::table_name, "`value`", 0);

  template <typename A>
  const typename pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::snmpObjectFk_type_
  pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::
  snmpObjectFk (A::table_name, "`snmpObjectFk`", 0);

  template <typename A>
  const typename pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::snmpObjectTypeFk_type_
  pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::
  snmpObjectTypeFk (A::table_name, "`snmpObjectTypeFk`", 0);

  template <typename A>
  const typename pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::monitorHistoryFk_type_
  pointer_query_columns< ::SnmpObjectValue, id_mysql, A >::
  monitorHistoryFk (A::table_name, "`monitorHistoryFk`", 0);

  template <>
  class access::object_traits_impl< ::SnmpObjectValue, id_mysql >:
    public access::object_traits< ::SnmpObjectValue >
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
      // snmpObjectValueId_
      //
      unsigned long long snmpObjectValueId_value;
      my_bool snmpObjectValueId_null;

      // value_
      //
      details::buffer value_value;
      unsigned long value_size;
      my_bool value_null;

      // snmpObjectFk_
      //
      unsigned long long snmpObjectFk_value;
      my_bool snmpObjectFk_null;

      // snmpObjectTypeFk_
      //
      unsigned long long snmpObjectTypeFk_value;
      my_bool snmpObjectTypeFk_null;

      // monitorHistoryFk_
      //
      unsigned long long monitorHistoryFk_value;
      my_bool monitorHistoryFk_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct snmpObjectFk_tag;
    struct snmpObjectTypeFk_tag;
    struct monitorHistoryFk_tag;

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

    static const std::size_t column_count = 5UL;
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
  class access::object_traits_impl< ::SnmpObjectValue, id_common >:
    public access::object_traits_impl< ::SnmpObjectValue, id_mysql >
  {
  };

  // SnmpObjectValue
  //
  template <>
  struct alias_traits<
    ::SnmpObject,
    id_mysql,
    access::object_traits_impl< ::SnmpObjectValue, id_mysql >::snmpObjectFk_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::SnmpObjectType,
    id_mysql,
    access::object_traits_impl< ::SnmpObjectValue, id_mysql >::snmpObjectTypeFk_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::MonitorHistory,
    id_mysql,
    access::object_traits_impl< ::SnmpObjectValue, id_mysql >::monitorHistoryFk_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::SnmpObjectValue, id_mysql >
  {
    // snmpObjectFk
    //
    typedef
    odb::alias_traits<
      ::SnmpObject,
      id_mysql,
      access::object_traits_impl< ::SnmpObjectValue, id_mysql >::snmpObjectFk_tag>
    snmpObjectFk_alias_;

    // snmpObjectTypeFk
    //
    typedef
    odb::alias_traits<
      ::SnmpObjectType,
      id_mysql,
      access::object_traits_impl< ::SnmpObjectValue, id_mysql >::snmpObjectTypeFk_tag>
    snmpObjectTypeFk_alias_;

    // monitorHistoryFk
    //
    typedef
    odb::alias_traits<
      ::MonitorHistory,
      id_mysql,
      access::object_traits_impl< ::SnmpObjectValue, id_mysql >::monitorHistoryFk_tag>
    monitorHistoryFk_alias_;
  };

  template <typename A>
  struct query_columns< ::SnmpObjectValue, id_mysql, A >:
    query_columns_base< ::SnmpObjectValue, id_mysql >
  {
    // snmpObjectValueId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectValueId_type_;

    static const snmpObjectValueId_type_ snmpObjectValueId;

    // value
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    value_type_;

    static const value_type_ value;

    // snmpObjectFk
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectFk_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::SnmpObject,
        id_mysql,
        snmpObjectFk_alias_ > >
    snmpObjectFk_pointer_type_;

    struct snmpObjectFk_type_: snmpObjectFk_pointer_type_, snmpObjectFk_column_type_
    {
      snmpObjectFk_type_ (const char* t, const char* c, const char* conv)
        : snmpObjectFk_column_type_ (t, c, conv)
      {
      }
    };

    static const snmpObjectFk_type_ snmpObjectFk;

    // snmpObjectTypeFk
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectTypeFk_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::SnmpObjectType,
        id_mysql,
        snmpObjectTypeFk_alias_ > >
    snmpObjectTypeFk_pointer_type_;

    struct snmpObjectTypeFk_type_: snmpObjectTypeFk_pointer_type_, snmpObjectTypeFk_column_type_
    {
      snmpObjectTypeFk_type_ (const char* t, const char* c, const char* conv)
        : snmpObjectTypeFk_column_type_ (t, c, conv)
      {
      }
    };

    static const snmpObjectTypeFk_type_ snmpObjectTypeFk;

    // monitorHistoryFk
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    monitorHistoryFk_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::MonitorHistory,
        id_mysql,
        monitorHistoryFk_alias_ > >
    monitorHistoryFk_pointer_type_;

    struct monitorHistoryFk_type_: monitorHistoryFk_pointer_type_, monitorHistoryFk_column_type_
    {
      monitorHistoryFk_type_ (const char* t, const char* c, const char* conv)
        : monitorHistoryFk_column_type_ (t, c, conv)
      {
      }
    };

    static const monitorHistoryFk_type_ monitorHistoryFk;
  };

  template <typename A>
  const typename query_columns< ::SnmpObjectValue, id_mysql, A >::snmpObjectValueId_type_
  query_columns< ::SnmpObjectValue, id_mysql, A >::
  snmpObjectValueId (A::table_name, "`snmpObjectValueId`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObjectValue, id_mysql, A >::value_type_
  query_columns< ::SnmpObjectValue, id_mysql, A >::
  value (A::table_name, "`value`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObjectValue, id_mysql, A >::snmpObjectFk_type_
  query_columns< ::SnmpObjectValue, id_mysql, A >::
  snmpObjectFk (A::table_name, "`snmpObjectFk`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObjectValue, id_mysql, A >::snmpObjectTypeFk_type_
  query_columns< ::SnmpObjectValue, id_mysql, A >::
  snmpObjectTypeFk (A::table_name, "`snmpObjectTypeFk`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObjectValue, id_mysql, A >::monitorHistoryFk_type_
  query_columns< ::SnmpObjectValue, id_mysql, A >::
  monitorHistoryFk (A::table_name, "`monitorHistoryFk`", 0);
}

#include "SnmpObjectValue_odb_inline.h"

#include <odb/post.hxx>

#endif // SNMP_OBJECT_VALUE_ODB_H
