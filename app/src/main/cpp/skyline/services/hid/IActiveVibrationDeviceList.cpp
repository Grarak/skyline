// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include "IActiveVibrationDeviceList.h"

namespace skyline::service::hid {

    IActiveVibrationDeviceList::IActiveVibrationDeviceList(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager, Service::hid_IActiveVibrationDeviceList, "hid:IActiveVibrationDeviceList", {
        {0x0, SFUNC(IActiveVibrationDeviceList::ActivateVibrationDevice)}
    }) {
    }

    void IActiveVibrationDeviceList::ActivateVibrationDevice(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        auto deviceHandle = request.Pop<u32>();
    }
}
