// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef NETWORK_ELEMENT_ODB_H
#define NETWORK_ELEMENT_ODB_H

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

#include "NetworkElement.hpp"

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
  // NetworkElement
  //
  template <>
  struct class_traits< ::NetworkElement >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::NetworkElement >
  {
    public:
    typedef ::NetworkElement object_type;
    typedef ::std::shared_ptr< ::NetworkElement > pointer_type;
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
  // NetworkElement
  //
  template <typename A>
  struct query_columns< ::NetworkElement, id_mysql, A >
  {
    // networkElementId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    networkElementId_type_;

    static const networkElementId_type_ networkElementId;

    // elementName
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    elementName_type_;

    static const elementName_type_ elementName;

    // macAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    macAddress_type_;

    static const macAddress_type_ macAddress;

    // ipAddress
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    ipAddress_type_;

    static const ipAddress_type_ ipAddress;
  };

  template <typename A>
  const typename query_columns< ::NetworkElement, id_mysql, A >::networkElementId_type_
  query_columns< ::NetworkElement, id_mysql, A >::
  networkElementId (A::table_name, "`networkElementId`", 0);

  template <typename A>
  const typename query_columns< ::NetworkElement, id_mysql, A >::elementName_type_
  query_columns< ::NetworkElement, id_mysql, A >::
  elementName (A::table_name, "`elementName`", 0);

  template <typename A>
  const typename query_columns< ::NetworkElement, id_mysql, A >::macAddress_type_
  query_columns< ::NetworkElement, id_mysql, A >::
  macAddress (A::table_name, "`macAddress`", 0);

  template <typename A>
  const typename query_columns< ::NetworkElement, id_mysql, A >::ipAddress_type_
  query_columns< ::NetworkElement, id_mysql, A >::
  ipAddress (A::table_name, "`ipAddress`", 0);

  template <typename A>
  struct pointer_query_columns< ::NetworkElement, id_mysql, A >:
    query_columns< ::NetworkElement, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::NetworkElement, id_mysql >:
    public access::object_traits< ::NetworkElement >
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
      // networkElementId_
      //
      unsigned long long networkElementId_value;
      my_bool networkElementId_null;

      // elementName_
      //
      details::buffer elementName_value;
      unsigned long elementName_size;
      my_bool elementName_null;

      // macAddress_
      //
      details::buffer macAddress_value;
      unsigned long macAddress_size;
      my_bool macAddress_null;

      // ipAddress_
      //
      details::buffer ipAddress_value;
      unsigned long ipAddress_size;
      my_bool ipAddress_null;

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
  class access::object_traits_impl< ::NetworkElement, id_common >:
    public access::object_traits_impl< ::NetworkElement, id_mysql >
  {
  };

  // NetworkElement
  //
}

#include "NetworkElement_odb_inline.h"

#include <odb/post.hxx>

#endif // NETWORK_ELEMENT_ODB_H
