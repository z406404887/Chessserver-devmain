// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: qpserver.proto

#include "qpserver.pb.h"
#include "qpserver.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace qpserver {

static const char* Logon_method_names[] = {
  "/qpserver.Logon/SendSms",
  "/qpserver.Logon/VerifySms",
  "/qpserver.Logon/EraseSms",
  "/qpserver.Logon/RegPreVerify",
  "/qpserver.Logon/UpdateUser",
  "/qpserver.Logon/MapUser",
};

std::unique_ptr< Logon::Stub> Logon::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Logon::Stub> stub(new Logon::Stub(channel));
  return stub;
}

Logon::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SendSms_(Logon_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_VerifySms_(Logon_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_EraseSms_(Logon_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RegPreVerify_(Logon_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_UpdateUser_(Logon_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MapUser_(Logon_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Logon::Stub::SendSms(::grpc::ClientContext* context, const ::qpserver::ReqSendSms& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SendSms_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::AsyncSendSmsRaw(::grpc::ClientContext* context, const ::qpserver::ReqSendSms& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_SendSms_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::PrepareAsyncSendSmsRaw(::grpc::ClientContext* context, const ::qpserver::ReqSendSms& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_SendSms_, context, request, false);
}

::grpc::Status Logon::Stub::VerifySms(::grpc::ClientContext* context, const ::qpserver::ReqVerifySms& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_VerifySms_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::AsyncVerifySmsRaw(::grpc::ClientContext* context, const ::qpserver::ReqVerifySms& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_VerifySms_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::PrepareAsyncVerifySmsRaw(::grpc::ClientContext* context, const ::qpserver::ReqVerifySms& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_VerifySms_, context, request, false);
}

::grpc::Status Logon::Stub::EraseSms(::grpc::ClientContext* context, const ::qpserver::ReqSendSms& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_EraseSms_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::AsyncEraseSmsRaw(::grpc::ClientContext* context, const ::qpserver::ReqSendSms& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_EraseSms_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::PrepareAsyncEraseSmsRaw(::grpc::ClientContext* context, const ::qpserver::ReqSendSms& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_EraseSms_, context, request, false);
}

::grpc::Status Logon::Stub::RegPreVerify(::grpc::ClientContext* context, const ::qpserver::ReqRegVerifyItem& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RegPreVerify_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::AsyncRegPreVerifyRaw(::grpc::ClientContext* context, const ::qpserver::ReqRegVerifyItem& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_RegPreVerify_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::PrepareAsyncRegPreVerifyRaw(::grpc::ClientContext* context, const ::qpserver::ReqRegVerifyItem& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_RegPreVerify_, context, request, false);
}

::grpc::Status Logon::Stub::UpdateUser(::grpc::ClientContext* context, const ::qpserver::ReqUpdUser& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_UpdateUser_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::AsyncUpdateUserRaw(::grpc::ClientContext* context, const ::qpserver::ReqUpdUser& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_UpdateUser_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::PrepareAsyncUpdateUserRaw(::grpc::ClientContext* context, const ::qpserver::ReqUpdUser& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_UpdateUser_, context, request, false);
}

::grpc::Status Logon::Stub::MapUser(::grpc::ClientContext* context, const ::qpserver::ReqMapUser& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_MapUser_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::AsyncMapUserRaw(::grpc::ClientContext* context, const ::qpserver::ReqMapUser& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_MapUser_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Logon::Stub::PrepareAsyncMapUserRaw(::grpc::ClientContext* context, const ::qpserver::ReqMapUser& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_MapUser_, context, request, false);
}

Logon::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Logon_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Logon::Service, ::qpserver::ReqSendSms, ::qpserver::RepRet>(
          std::mem_fn(&Logon::Service::SendSms), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Logon_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Logon::Service, ::qpserver::ReqVerifySms, ::qpserver::RepRet>(
          std::mem_fn(&Logon::Service::VerifySms), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Logon_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Logon::Service, ::qpserver::ReqSendSms, ::qpserver::RepRet>(
          std::mem_fn(&Logon::Service::EraseSms), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Logon_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Logon::Service, ::qpserver::ReqRegVerifyItem, ::qpserver::RepRet>(
          std::mem_fn(&Logon::Service::RegPreVerify), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Logon_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Logon::Service, ::qpserver::ReqUpdUser, ::qpserver::RepRet>(
          std::mem_fn(&Logon::Service::UpdateUser), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Logon_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Logon::Service, ::qpserver::ReqMapUser, ::qpserver::RepRet>(
          std::mem_fn(&Logon::Service::MapUser), this)));
}

Logon::Service::~Service() {
}

::grpc::Status Logon::Service::SendSms(::grpc::ServerContext* context, const ::qpserver::ReqSendSms* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Logon::Service::VerifySms(::grpc::ServerContext* context, const ::qpserver::ReqVerifySms* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Logon::Service::EraseSms(::grpc::ServerContext* context, const ::qpserver::ReqSendSms* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Logon::Service::RegPreVerify(::grpc::ServerContext* context, const ::qpserver::ReqRegVerifyItem* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Logon::Service::UpdateUser(::grpc::ServerContext* context, const ::qpserver::ReqUpdUser* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Logon::Service::MapUser(::grpc::ServerContext* context, const ::qpserver::ReqMapUser* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* Game_method_names[] = {
  "/qpserver.Game/GamePlayStatis",
};

std::unique_ptr< Game::Stub> Game::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Game::Stub> stub(new Game::Stub(channel));
  return stub;
}

Game::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_GamePlayStatis_(Game_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Game::Stub::GamePlayStatis(::grpc::ClientContext* context, const ::qpserver::ReqInOutGame& request, ::qpserver::RepRet* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GamePlayStatis_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Game::Stub::AsyncGamePlayStatisRaw(::grpc::ClientContext* context, const ::qpserver::ReqInOutGame& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_GamePlayStatis_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::qpserver::RepRet>* Game::Stub::PrepareAsyncGamePlayStatisRaw(::grpc::ClientContext* context, const ::qpserver::ReqInOutGame& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::qpserver::RepRet>::Create(channel_.get(), cq, rpcmethod_GamePlayStatis_, context, request, false);
}

Game::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Game_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Game::Service, ::qpserver::ReqInOutGame, ::qpserver::RepRet>(
          std::mem_fn(&Game::Service::GamePlayStatis), this)));
}

Game::Service::~Service() {
}

::grpc::Status Game::Service::GamePlayStatis(::grpc::ServerContext* context, const ::qpserver::ReqInOutGame* request, ::qpserver::RepRet* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace qpserver

