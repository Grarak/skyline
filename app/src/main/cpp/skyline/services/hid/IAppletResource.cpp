// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include "IAppletResource.h"

namespace skyline::service::hid {
    IAppletResource::IAppletResource(const DeviceState &state, ServiceManager &manager) : BaseService(state, manager, Service::hid_IAppletResource, "hid:IAppletResource", {
        {0x0, SFUNC(IAppletResource::GetSharedMemoryHandle)}
    }), hidSharedMemory(state.input->hidKMem) {}

    void IAppletResource::GetSharedMemoryHandle(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        auto handle = state.process->InsertItem<type::KSharedMemory>(hidSharedMemory);
        state.logger->Debug("HID Shared Memory Handle: 0x{:X}", handle);

        response.copyHandles.push_back(handle);
    }
}
