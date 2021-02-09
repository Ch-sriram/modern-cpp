.PHONY: clean All

All:
	@echo "----------Building project:[ HelloTesting - Debug ]----------"
	@cd "HelloTesting" && "$(MAKE)" -f  "HelloTesting.mk"
clean:
	@echo "----------Cleaning project:[ HelloTesting - Debug ]----------"
	@cd "HelloTesting" && "$(MAKE)" -f  "HelloTesting.mk" clean
