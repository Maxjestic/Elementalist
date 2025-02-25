// Copyright Maxjestic

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ElementalistCharacter.generated.h"

UCLASS()
class ELEMENTALIST_API AElementalistCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AElementalistCharacter();
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

};
