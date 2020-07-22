// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <input.h>
#include <kernel/types/KProcess.h>
#include <services/base_service.h>
#include <services/serviceman.h>

namespace skyline::service::hid {
    /**
     * @brief IActiveVibrationDeviceList is used to get a handle to the HID shared memory (https://switchbrew.org/wiki/HID_services#IActiveVibrationDeviceList)
     */
    class IActiveVibrationDeviceList : public BaseService {
      public:
        IActiveVibrationDeviceList(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Activates vibration device with handle (Stubbed)
         * @url https://switchbrew.org/wiki/HID_services#ActivateVibrationDevice
         */
        void ActivateVibrationDevice(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);
    };
}
