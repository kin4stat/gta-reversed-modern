#include "StdInc.h"
#include "detours.h"

#pragma comment(lib, "detours.lib")

//bool __thiscall CTaskSimpleSwim_ProcessControlInput(CPhysical* pThis)
auto OLD_CTaskSimpleSwim_ProcessControlInput = (void(__thiscall*) (CTaskSimpleSwim * pThis, CPlayerPed * pPed))0x688A90;
void __fastcall CTaskSimpleSwim_ProcessControlInput(CTaskSimpleSwim* pThis, void* padding, CPlayerPed* pPed);

void __cdecl HOOK_THEFUNCTION();

void InjectHooksMain(void)
{
    /*CAnimManager::InjectHooks();
    pTaskManager->InjectHooks();
    std::printf("okay, only CAnimManager and CTaskManager hooks\n ");
    CStreaming::InjectHooks();
    CRenderer::InjectHooks();*/

    //HookInstall(0x688A90, &CTaskSimpleSwim::ProcessControlInput, 7);

  /*
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    std::printf("GOING TO HOOK FUNC NOW\n");
    DetourAttach(&(PVOID&)OLD_CTaskSimpleSwim_ProcessControlInput, CTaskSimpleSwim_ProcessControlInput);
    DetourTransactionCommit();
     /*/
}
/*
enum eFunctionReturnValue
{
    FUNCTION_RETURN = 0,
    FUNCTION_INSIDE_IF = 1,
    FUNCTION_OUTSIDE_IF = 2
};
*/
/*
dwReturnLocation:
0 means that the function should return.
1 means continue the function and it is inside of the "if" condition
2 means continue the function and it is outside of the "if" condition
*/

enum eFunctionReturnValue
{
    FUNCTION_RETURN = 0,
    FUNCTION_INSIDE_IF = 1,
    FUNCTION_OUTSIDE_IF = 2,
    FUNCTION_SWITCH_CASE_2 = 3,
    FUNCTION_SOMELABEL = 4
};

void __fastcall CTaskSimpleSwim_ProcessControlInput(CTaskSimpleSwim* pThis, void* padding, CPlayerPed* pPed)
{
    printf(" calling CTaskSimpleSwim_ProcessControlInput \n");

  
}
