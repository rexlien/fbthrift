/*
 * Copyright 2017-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <thrift/lib/cpp2/protocol/Cpp2Ops.h>

#include <type_traits>

#include <folly/Traits.h>
#include <folly/io/IOBuf.h>

namespace apache {
    namespace thrift {

        namespace detail {

            template <typename C>
            using push_back_result = decltype(
                std::declval<C&>().push_back(std::declval<typename C::value_type>()));

            template <typename C>
            using insert_key_result =
                decltype(std::declval<C&>().insert(std::declval<typename C::key_type>()));

            template <typename C>
            using subscript_key_result =
                decltype(std::declval<C&>()[std::declval<typename C::key_type>()]);

            template <typename C>
            using reserve_result =
                decltype(std::declval<C&>().reserve(std::declval<typename C::size_type>()));
            template <typename C, typename = void>
            struct Reserver {
                static void reserve(C&, typename C::size_type) {}
            };
            template <typename C>
            struct Reserver<C, folly::void_t<reserve_result<C>>> {
                static void reserve(C& container, typename C::size_type size) {
                    container.reserve(size);
                }
            };

        } // namespace detail

        template <>
        class Cpp2Ops<folly::fbstring> {
        public:
            typedef folly::fbstring Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_STRING;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeString(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readString(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeString(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeString(*value);
            }
        };

        template <>
        class Cpp2Ops<std::string> {
        public:
            typedef std::string Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_STRING;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeString(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readString(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeString(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeString(*value);
            }
        };

        template <>
        class Cpp2Ops<int8_t> {
        public:
            typedef int8_t Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_BYTE;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeByte(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readByte(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeByte(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeByte(*value);
            }
        };

        template <>
        class Cpp2Ops<int16_t> {
        public:
            typedef int16_t Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_I16;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeI16(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readI16(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeI16(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeI16(*value);
            }
        };

        template <>
        class Cpp2Ops<int32_t> {
        public:
            typedef int32_t Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_I32;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeI32(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readI32(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeI32(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeI32(*value);
            }
        };

        template <>
        class Cpp2Ops<int64_t> {
        public:
            typedef int64_t Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_I64;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeI64(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readI64(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeI64(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeI64(*value);
            }
        };

        template <>
        class Cpp2Ops<bool> {
        public:
            typedef bool Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_BOOL;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeBool(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readBool(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeBool(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeBool(*value);
            }
        };

        template <>
        class Cpp2Ops<double> {
        public:
            typedef double Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_DOUBLE;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeDouble(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readDouble(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeDouble(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeDouble(*value);
            }
        };

        template <class E>
        class Cpp2Ops<E, typename std::enable_if<std::is_enum<E>::value>::type> {
        public:
            typedef E Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_I32;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeI32(static_cast<int32_t>(*value));
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readI32(reinterpret_cast<int32_t&>(*value));
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeI32(static_cast<int32_t>(*value));
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeI32(static_cast<int32_t>(*value));
            }
        };

        template <>
        class Cpp2Ops<float> {
        public:
            typedef float Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_FLOAT;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeFloat(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readFloat(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeFloat(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeFloat(*value);
            }
        };

        namespace detail {

            template <class Protocol, class V>
            uint32_t readIntoVector(Protocol* prot, V& vec) {
                typedef typename V::value_type ElemType;
                uint32_t xfer = 0;
                for (auto& e : vec) {
                    xfer += Cpp2Ops<ElemType>::read(prot, &e);
                }
                return xfer;
            }

            template <class Protocol>
            uint32_t readIntoVector(Protocol* prot, std::vector<bool>& vec) {
                uint32_t xfer = 0;
                for (auto e : vec) {
                    // e is a proxy object because the elements don't have distinct addresses
                    // (packed into a bitvector). We actually copy the proxy during iteration
                    // (can't use non-const reference because iteration returns by value, can't
                    // use const reference because we modify it), but it still points to the
                    // actual element.
                    bool b;
                    xfer += Cpp2Ops<bool>::read(prot, &b);
                    e = b;
                }
                return xfer;
            }

        } // namespace detail

        template <class L>
        class Cpp2Ops<L, folly::void_t<detail::push_back_result<L>>> {
        public:
            typedef L Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_LIST;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                typedef typename Type::value_type ElemType;
                uint32_t xfer = 0;
                xfer +=
                    prot->writeListBegin(Cpp2Ops<ElemType>::thriftType(), value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<ElemType>::write(prot, &e);
                }
                xfer += prot->writeListEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                value->clear();
                uint32_t xfer = 0;
                uint32_t size;
                protocol::TType etype;
                xfer += prot->readListBegin(etype, size);
                value->resize(size);
                xfer += detail::readIntoVector(prot, *value);
                xfer += prot->readListEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                typedef typename Type::value_type ElemType;
                uint32_t xfer = 0;
                xfer += prot->serializedSizeListBegin(
                    Cpp2Ops<ElemType>::thriftType(), value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<ElemType>::serializedSize(prot, &e);
                }
                xfer += prot->serializedSizeListEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                typedef typename Type::value_type ElemType;
                uint32_t xfer = 0;
                xfer += prot->serializedSizeListBegin(
                    Cpp2Ops<ElemType>::thriftType(), value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<ElemType>::serializedSizeZC(prot, &e);
                }
                xfer += prot->serializedSizeListEnd();
                return xfer;
            }
        };

        template <class S>
        class Cpp2Ops<S, folly::void_t<detail::insert_key_result<S>>> {
        public:
            typedef S Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_SET;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                typedef typename Type::key_type ElemType;
                uint32_t xfer = 0;
                xfer += prot->writeSetBegin(Cpp2Ops<ElemType>::thriftType(), value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<ElemType>::write(prot, &e);
                }
                xfer += prot->writeSetEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                typedef typename Type::key_type ElemType;
                value->clear();
                uint32_t xfer = 0;
                uint32_t size;
                protocol::TType etype;
                xfer += prot->readSetBegin(etype, size);
                detail::Reserver<Type>::reserve(*value, size);
                for (uint32_t i = 0; i < size; i++) {
                    ElemType elem;
                    xfer += Cpp2Ops<ElemType>::read(prot, &elem);
                    value->insert(std::move(elem));
                }
                xfer += prot->readSetEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                typedef typename Type::key_type ElemType;
                uint32_t xfer = 0;
                xfer += prot->serializedSizeSetBegin(
                    Cpp2Ops<ElemType>::thriftType(), value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<ElemType>::serializedSize(prot, &e);
                }
                xfer += prot->serializedSizeSetEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                typedef typename Type::key_type ElemType;
                uint32_t xfer = 0;
                xfer += prot->serializedSizeSetBegin(
                    Cpp2Ops<ElemType>::thriftType(), value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<ElemType>::serializedSizeZC(prot, &e);
                }
                xfer += prot->serializedSizeSetEnd();
                return xfer;
            }
        };

        template <class M>
        class Cpp2Ops<M, folly::void_t<detail::subscript_key_result<M>>> {
        public:
            typedef M Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_MAP;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                typedef typename Type::key_type KeyType;
                typedef typename std::remove_cv<typename std::remove_reference<decltype(
                    *value->begin())>::type>::type PairType;
                typedef typename PairType::second_type ValueType;
                uint32_t xfer = 0;
                xfer += prot->writeMapBegin(
                    Cpp2Ops<KeyType>::thriftType(),
                    Cpp2Ops<ValueType>::thriftType(),
                    value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<KeyType>::write(prot, &e.first);
                    xfer += Cpp2Ops<ValueType>::write(prot, &e.second);
                }
                xfer += prot->writeMapEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                typedef typename Type::key_type KeyType;
                // We do this dance with decltype rather than just using Type::mapped_type
                // because different map implementations (such as Google's dense_hash_map)
                // call it data_type.
                typedef typename std::remove_cv<typename std::remove_reference<decltype(
                    *value->begin())>::type>::type PairType;
                typedef typename PairType::second_type ValueType;
                value->clear();
                uint32_t xfer = 0;
                uint32_t size;
                protocol::TType keytype, valuetype;
                xfer += prot->readMapBegin(keytype, valuetype, size);
                detail::Reserver<Type>::reserve(*value, size);
                for (uint32_t i = 0; i < size; i++) {
                    KeyType key;
                    xfer += Cpp2Ops<KeyType>::read(prot, &key);
                    auto& val = (*value)[std::move(key)];
                    xfer += Cpp2Ops<ValueType>::read(prot, &val);
                }
                xfer += prot->readMapEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                typedef typename Type::key_type KeyType;
                typedef typename std::remove_cv<typename std::remove_reference<decltype(
                    *value->begin())>::type>::type PairType;
                typedef typename PairType::second_type ValueType;
                uint32_t xfer = 0;
                xfer += prot->serializedSizeMapBegin(
                    Cpp2Ops<KeyType>::thriftType(),
                    Cpp2Ops<ValueType>::thriftType(),
                    value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<KeyType>::serializedSize(prot, &e.first);
                    xfer += Cpp2Ops<ValueType>::serializedSize(prot, &e.second);
                }
                xfer += prot->serializedSizeMapEnd();
                return xfer;
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                typedef typename Type::key_type KeyType;
                typedef typename std::remove_cv<typename std::remove_reference<decltype(
                    *value->begin())>::type>::type PairType;
                typedef typename PairType::second_type ValueType;
                uint32_t xfer = 0;
                xfer += prot->serializedSizeMapBegin(
                    Cpp2Ops<KeyType>::thriftType(),
                    Cpp2Ops<ValueType>::thriftType(),
                    value->size());
                for (const auto& e : *value) {
                    xfer += Cpp2Ops<KeyType>::serializedSizeZC(prot, &e.first);
                    xfer += Cpp2Ops<ValueType>::serializedSizeZC(prot, &e.second);
                }
                xfer += prot->serializedSizeMapEnd();
                return xfer;
            }
        };

        template <>
        class Cpp2Ops<folly::IOBuf> {
        public:
            typedef folly::IOBuf Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_STRING;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeBinary(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readBinary(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeBinary(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeZCBinary(*value);
            }
        };

        template <>
        class Cpp2Ops<std::unique_ptr<folly::IOBuf>> {
        public:
            typedef std::unique_ptr<folly::IOBuf> Type;
            static constexpr protocol::TType thriftType() {
                return protocol::T_STRING;
            }
            template <class Protocol>
            static uint32_t write(Protocol* prot, const Type* value) {
                return prot->writeBinary(*value);
            }
            template <class Protocol>
            static uint32_t read(Protocol* prot, Type* value) {
                return prot->readBinary(*value);
            }
            template <class Protocol>
            static uint32_t serializedSize(Protocol* prot, const Type* value) {
                return prot->serializedSizeBinary(*value);
            }
            template <class Protocol>
            static uint32_t serializedSizeZC(Protocol* prot, const Type* value) {
                return prot->serializedSizeZCBinary(*value);
            }
        };

    } // namespace thrift
} // namespace apache