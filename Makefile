# Variables
CHECK_SCRIPT := ./scripts/check.sh

# Default target: check without parameters
.PHONY: check
check:
	@$(CHECK_SCRIPT) $(filter-out $@,$(MAKECMDGOALS))

# Target to display help from check.sh
.PHONY: check\:help
check\:help:
	@echo "Checks the main.cpp files in the specified directory or all directories under ./src."
	@echo
	@echo "Usage:"
	@echo "  make check [relative_path]"
	@echo
	@echo "Arguments:"
	@echo "  relative_path    Optional. Relative path to the folder to check (e.g., '2023/day-01/part-1')."
	@echo
	@echo "Examples:"
	@echo "  make check               # Checks all main.cpp files in the ./src directory."
	@echo "  make check 2023/day-01/part-1 # Checks the main.cpp file in ./src/2023/day-01/part-1."

# Catch-all target to handle additional arguments
%:
	@: