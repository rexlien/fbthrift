/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#pragma once
#include <src/gen-cpp2/TestService.h>
#include <Python.h>

#include <memory>

namespace cpp2 {

class TestServiceWrapper : virtual public TestServiceSvIf {
  protected:
    PyObject *if_object;
  public:
    explicit TestServiceWrapper(PyObject *if_object);
    virtual ~TestServiceWrapper();
    folly::Future<int64_t> future_init(
        int64_t int1
    ) override;
};

std::shared_ptr<apache::thrift::ServerInterface> TestServiceInterface(PyObject *if_object);
} // namespace cpp2