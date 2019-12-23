/*
 *
 * Copyright 2019 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPCPP_SECURITY_ALTS_UTIL_H
#define GRPCPP_SECURITY_ALTS_UTIL_H

#include <grpc/grpc_security_constants.h>
#include <grpcpp/impl/codegen/security/auth_context.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/security/alts_context.h>

#include <memory>

struct grpc_gcp_AltsContext;

namespace grpc {
namespace experimental {
// GetAltsContextFromAuthContext helps to get the AltsContext from AuthContext.
// If ALTS is not the transport security protocol used to establish the
// connection, this function will return nullptr.
std::unique_ptr<AltsContext> GetAltsContextFromAuthContext(
    const AuthContext& auth_context);
// AltsClientAuthzCheck is a helper function for clients to check server
// identities.
grpc::Status AltsClientAuthzCheck(
    const AuthContext& auth_context,
    const std::vector<std::string>& expected_service_accounts);

}  // namespace experimental
}  // namespace grpc

#endif  // GRPCPP_SECURITY_ALTS_UTIL_H
