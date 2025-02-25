// Copyright Maxjestic

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ElementalistPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

/**
 * Default controller class in the game
 */
UCLASS()
class ELEMENTALIST_API AElementalistPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	//~ End AActor Interface

private:
	/** Callback for Move InputAction */
	void Move(const FInputActionValue& InputActionValue);
	
	/** Callback for Look InputAction */
	void Look(const FInputActionValue& InputActionValue);

	UPROPERTY( EditAnywhere, Category = "Input" )
	TObjectPtr<UInputMappingContext> ElementalistContext;
	
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> LookAction;
};
