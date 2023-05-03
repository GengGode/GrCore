//
// Created by YuSuiXian on 2023/5/3.
//

#ifndef GRCORE_GRCORE_H
#define GRCORE_GRCORE_H

#ifdef GRCORE_EXPORTS
#define GR_API __declspec(dllexport)
#else
#define GR_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef struct GrCoreResult{
    bool success;
    void* result;
    int err_code;
    const char* err_msg;
} Result;
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
GrCoreResult GR_API GrCoreHandleCreate(void*& handle);
GrCoreResult GR_API GrCoreHandleDestroy(void* handle);

#ifdef __cplusplus
}
#endif

#endif //GRCORE_GRCORE_H
