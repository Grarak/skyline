// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <input.h>
#include <kernel/types/KProcess.h>
#include <services/base_service.h>
#include <services/serviceman.h>

namespace skyline {

    namespace service::hid {
        /**
         * @brief IAppletResource is used to get a handle to the HID shared memory (https://switchbrew.org/wiki/HID_services#IAppletResource)
         */
        class IAppletResource : public BaseService {
          public:
            std::shared_ptr<type::KSharedMemory> hidSharedMemory; //!< A pointer to HID shared memory

            IAppletResource(const DeviceState &state, ServiceManager &manager);

            /**
             * @brief This opens a handle to HID shared memory (https://switchbrew.org/wiki/HID_services#GetSharedMemoryHandle)
             */
            void GetSharedMemoryHandle(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);
        };
    }
}
