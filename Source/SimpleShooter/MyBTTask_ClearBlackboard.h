// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_ClearBlackboard.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API UMyBTTask_ClearBlackboard : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UMyBTTask_ClearBlackboard() { NodeName = TEXT("Clear Blackboard Value"); }
protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
