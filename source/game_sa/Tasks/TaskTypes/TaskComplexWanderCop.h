#pragma once

#include "TaskComplexWander.h"
#include "TaskComplexGoToPointAndStandStill.h"
#include "TaskTimer.h"

class CPed;

class NOTSA_EXPORT_VTABLE CTaskComplexWanderCop : public CTaskComplexWander {
public:
    CTaskComplexGoToPointAndStandStill* m_pGoToPointAndStandStillTask;
    CTaskTimer                          m_nScanForStuffTimer;
    uint32                              m_nTimePassedSinceLastLookedForCriminals;
    uint32                              m_nTimePassedSinceLastLookedForCarAlarmsAndStolenCopCars;
    CPed*                               m_pLastCriminalPedLookedFor;
    CTaskTimer                          m_nSubTaskCreatedTimer;

public:
    CTaskComplexWanderCop(int32 moveState, uint8 dir);
    ~CTaskComplexWanderCop() override;

    eWanderType GetWanderType() override { return WANDER_TYPE_COP; } // 0x460D50
    CTask* Clone() override { return new CTaskComplexWanderCop(m_nMoveState, m_nDir); } // 0x460CE0
    CTask* CreateNextSubTask(CPed* ped) override;
    CTask* CreateFirstSubTask(CPed* ped) override;
    CTask* ControlSubTask(CPed* ped) override;
    void ScanForStuff(CPed* ped) override;

    void LookForCarAlarms(CPed* ped);
    void LookForStolenCopCars(CPed* ped);
    void LookForCriminals(CPed* ped);
    bool ShouldPursuePlayer(CPed* ped);

private:
    friend void InjectHooksMain();
    static void InjectHooks();

    CTaskComplexWanderCop* Constructor(int32 moveState, uint8 dir);

    CTask* Clone_Reversed();
    CTask* CreateNextSubTask_Reversed(CPed* ped);
    CTask* CreateFirstSubTask_Reversed(CPed* ped);
    CTask* ControlSubTask_Reversed(CPed* ped);
    void ScanForStuff_Reversed(CPed* ped);
};

VALIDATE_SIZE(CTaskComplexWanderCop, 0x50);
