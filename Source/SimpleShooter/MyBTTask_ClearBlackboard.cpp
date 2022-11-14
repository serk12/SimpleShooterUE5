// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_ClearBlackboard.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UMyBTTask_ClearBlackboard::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
    Super::ExecuteTask(OwnerComp, NodeMemory);
    OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    return EBTNodeResult::Succeeded;
}