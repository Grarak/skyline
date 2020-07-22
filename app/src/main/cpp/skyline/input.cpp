#include "input.h"

namespace skyline::input {
    Input::Input(const DeviceState &state) : state(state), commonNpad(std::make_unique<npad::CommonNpad>(state)), hidKMem(std::make_shared<kernel::type::KSharedMemory>(state, NULL, constant::HidSharedMemSize, memory::Permission(true, false, false))) {
        auto hidMem = reinterpret_cast<HidSharedMemory *>(hidKMem->kernel.address);

        for (uint i = 0; i < npad::constant::NpadCount; i++) {
            npad.at(i) = std::make_shared<npad::NpadDevice>(hidMem->npad.at(i), npad::IndexToNpadId(i));
        }
    }
}
