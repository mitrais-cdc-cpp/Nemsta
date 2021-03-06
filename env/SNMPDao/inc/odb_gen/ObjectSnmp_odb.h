// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef OBJECT_SNMP_ODB_H
#define OBJECT_SNMP_ODB_H

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

#include "ObjectSnmp.hpp"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#ifdef BOOST_TR1_MEMORY_HPP_INCLUDED
#  include <odb/tr1/wrapper-traits.hxx>
#  include <odb/tr1/pointer-traits.hxx>
#endif
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>
#include <odb/view-image.hxx>
#include <odb/view-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // SnmpObject
  //
  template <>
  struct class_traits< ::Mitrais::SNMPDao::Entity::SnmpObject >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Mitrais::SNMPDao::Entity::SnmpObject >
  {
    public:
    typedef ::Mitrais::SNMPDao::Entity::SnmpObject object_type;
    typedef ::boost::shared_ptr< ::Mitrais::SNMPDao::Entity::SnmpObject > pointer_type;
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

  // SnmpObject_stat
  //
  template <>
  struct class_traits< ::Mitrais::SNMPDao::Entity::SnmpObject_stat >
  {
    static const class_kind kind = class_view;
  };

  template <>
  class access::view_traits< ::Mitrais::SNMPDao::Entity::SnmpObject_stat >
  {
    public:
    typedef ::Mitrais::SNMPDao::Entity::SnmpObject_stat view_type;
    typedef ::boost::shared_ptr< ::Mitrais::SNMPDao::Entity::SnmpObject_stat > pointer_type;

    static void
    callback (database&, view_type&, callback_event);
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
  // SnmpObject
  //
  template <typename A>
  struct query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >
  {
    // snmpObjectId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    snmpObjectId_type_;

    static const snmpObjectId_type_ snmpObjectId;

    // mib
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    mib_type_;

    static const mib_type_ mib;

    // oid
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    oid_type_;

    static const oid_type_ oid;

    // objectName
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    objectName_type_;

    static const objectName_type_ objectName;
  };

  template <typename A>
  const typename query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::snmpObjectId_type_
  query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::
  snmpObjectId (A::table_name, "`snmpObjectId`", 0);

  template <typename A>
  const typename query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::mib_type_
  query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::
  mib (A::table_name, "`mib`", 0);

  template <typename A>
  const typename query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::oid_type_
  query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::
  oid (A::table_name, "`oid`", 0);

  template <typename A>
  const typename query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::objectName_type_
  query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >::
  objectName (A::table_name, "`objectName`", 0);

  template <typename A>
  struct pointer_query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >:
    query_columns< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql >:
    public access::object_traits< ::Mitrais::SNMPDao::Entity::SnmpObject >
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
      // snmpObjectId_
      //
      unsigned long long snmpObjectId_value;
      my_bool snmpObjectId_null;

      // mib_
      //
      details::buffer mib_value;
      unsigned long mib_size;
      my_bool mib_null;

      // oid_
      //
      details::buffer oid_value;
      unsigned long oid_size;
      my_bool oid_null;

      // objectName_
      //
      details::buffer objectName_value;
      unsigned long objectName_size;
      my_bool objectName_null;

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

    static const std::size_t column_count = 4UL;
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
  class access::object_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject, id_common >:
    public access::object_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql >
  {
  };

  // SnmpObject_stat
  //
  template <>
  class access::view_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject_stat, id_mysql >:
    public access::view_traits< ::Mitrais::SNMPDao::Entity::SnmpObject_stat >
  {
    public:
    struct image_type
    {
      // count
      //
      unsigned long long count_value;
      my_bool count_null;

      std::size_t version;
    };

    typedef mysql::view_statements<view_type> statements_type;

    typedef mysql::query_base query_base_type;
    struct query_columns;

    static const bool versioned = false;

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&);

    static void
    init (view_type&,
          const image_type&,
          database*);

    static const std::size_t column_count = 1UL;

    static query_base_type
    query_statement (const query_base_type&);

    static result<view_type>
    query (database&, const query_base_type&);
  };

  template <>
  class access::view_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject_stat, id_common >:
    public access::view_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject_stat, id_mysql >
  {
  };

  // SnmpObject
  //
  // SnmpObject_stat
  //
  struct access::view_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject_stat, id_mysql >::query_columns:
    odb::pointer_query_columns<
      ::Mitrais::SNMPDao::Entity::SnmpObject,
      id_mysql,
      odb::access::object_traits_impl< ::Mitrais::SNMPDao::Entity::SnmpObject, id_mysql > >
  {
  };
}

#include "ObjectSnmp_odb_inline.h"

#include <odb/post.hxx>

#endif // OBJECT_SNMP_ODB_H
