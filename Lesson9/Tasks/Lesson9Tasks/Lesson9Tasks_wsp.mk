.PHONY: clean All

All:
	@echo ----------Building project:[ RWTest - Debug ]----------
	@cd "RWTest" && "$(MAKE)" -f "RWTest.mk"
clean:
	@echo ----------Cleaning project:[ RWTest - Debug ]----------
	@cd "RWTest" && "$(MAKE)" -f "RWTest.mk" clean
