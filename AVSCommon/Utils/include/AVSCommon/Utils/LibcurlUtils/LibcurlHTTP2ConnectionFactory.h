/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_LIBCURLUTILS_LIBCURLHTTP2CONNECTIONFACTORY_H_
#define ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_LIBCURLUTILS_LIBCURLHTTP2CONNECTIONFACTORY_H_

#include <AVSCommon/Utils/HTTP2/HTTP2ConnectionFactoryInterface.h>

#include "LibcurlSetCurlOptionsCallbackFactoryInterface.h"

namespace alexaClientSDK {
namespace avsCommon {
namespace utils {
namespace libcurlUtils {

/**
 * A class that produces @c LibcurlHTTP2Connection instances.
 */
class LibcurlHTTP2ConnectionFactory : public avsCommon::utils::http2::HTTP2ConnectionFactoryInterface {
public:
    /**
     * Create a new instance of @c LibcurlHTTP2ConnectionFactory.
     *
     * @param curlOptionsCallbackFactory The optional factory for instances @c
     * LibcurlSetCurlOptionsCallbackFactoryInterface.
     * @return A new instance of @c LibcurlHTTP2ConnectionFactory.
     */
    static std::shared_ptr<avsCommon::utils::http2::HTTP2ConnectionFactoryInterface>
    createHTTP2ConnectionFactoryInterface(
        const std::shared_ptr<LibcurlSetCurlOptionsCallbackFactoryInterface>& curlOptionsCallbackFactory = nullptr);

    /// @name HTTP2ConnectionFactoryInterface methods.
    /// @{
    std::shared_ptr<avsCommon::utils::http2::HTTP2ConnectionInterface> createHTTP2Connection() override;
    /// *}

    /**
     * Constructor.
     *
     * @param curlOptionsCallbackFactory The optional factory for instances @c
     * LibcurlSetCurlOptionsCallbackFactoryInterface.
     */
    LibcurlHTTP2ConnectionFactory(
        const std::shared_ptr<LibcurlSetCurlOptionsCallbackFactoryInterface>& curlOptionsCallbackFactory = nullptr);

private:
    /// The optional @c LibcurlSetCurlOptionsCallbackFactoryInterface to set curl options when creating a new http2
    /// connection.
    std::shared_ptr<LibcurlSetCurlOptionsCallbackFactoryInterface> m_setCurlOptionsCallbackFactory;
};

}  // namespace libcurlUtils
}  // namespace utils
}  // namespace avsCommon
}  // namespace alexaClientSDK

#endif  // ALEXA_CLIENT_SDK_AVSCOMMON_UTILS_INCLUDE_AVSCOMMON_UTILS_LIBCURLUTILS_LIBCURLHTTP2CONNECTIONFACTORY_H_
