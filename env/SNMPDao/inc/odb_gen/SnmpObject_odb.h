// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef SNMP_OBJECT_ODB_H
#define SNMP_OBJECT_ODB_H

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "SnmpObject.hpp"

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
  // SnmpObject
  //
  template <>
  struct class_traits< ::SnmpObject >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::SnmpObject >
  {
    public:
    typedef ::SnmpObject object_type;
    typedef ::std::shared_ptr< ::SnmpObject > pointer_type;
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
  // SnmpObject
  //
  template <typename A>
  struct query_columns< ::SnmpObject, id_mysql, A >
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
  const typename query_columns< ::SnmpObject, id_mysql, A >::snmpObjectId_type_
  query_columns< ::SnmpObject, id_mysql, A >::
  snmpObjectId (A::table_name, "`snmpObjectId`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObject, id_mysql, A >::mib_type_
  query_columns< ::SnmpObject, id_mysql, A >::
  mib (A::table_name, "`mib`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObject, id_mysql, A >::oid_type_
  query_columns< ::SnmpObject, id_mysql, A >::
  oid (A::table_name, "`oid`", 0);

  template <typename A>
  const typename query_columns< ::SnmpObject, id_mysql, A >::objectName_type_
  query_columns< ::SnmpObject, id_mysql, A >::
  objectName (A::table_name, "`objectName`", 0);

  template <typename A>
  struct pointer_query_columns< ::SnmpObject, id_mysql, A >:
    query_columns< ::SnmpObject, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::SnmpObject, id_mysql >:
    public access::object_traits< ::SnmpObject >
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
  class access::object_traits_impl< ::SnmpObject, id_common >:
    public access::object_traits_impl< ::SnmpObject, id_mysql >
  {
  };

  // SnmpObject
  //
}

#include "SnmpObject_odb_inline.h"

#include <odb/post.hxx>

#endif // SNMP_OBJECT_ODB_H
