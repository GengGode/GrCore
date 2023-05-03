//
// Created by YuSuiXian on 2023/5/3.
//

#include "grcore.h"
// src
#include "grcore.handle.h"

GrCoreResult GrCoreHandleCreate(void*& handle)
{
    GrCoreResult result = {false, nullptr, 0, nullptr};
    try
    {
        handle = new Gr::Core::Handle();
        result.success = true;
    }
    catch (std::exception& e)
    {
        result.err_code = 1;
        result.err_msg = e.what();
    }
    return result;
}
