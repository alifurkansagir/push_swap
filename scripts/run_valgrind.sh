#!/usr/bin/env bash

# Usage: ./scripts/run_valgrind.sh [args...]
# If valgrind is available, runs: valgrind --leak-check=full ./push_swap [args]
# Otherwise prints install instructions for Linux/macOS and suggests alternatives.

if ! command -v valgrind >/dev/null 2>&1; then
  echo "valgrind not found on PATH."
  echo
  echo "Linux (Debian/Ubuntu):"
  echo "  sudo apt-get update && sudo apt-get install valgrind"
  echo
  echo "macOS:"
  echo "  Valgrind support on recent macOS versions is limited. Options:"
  echo "   - Use Docker with a Linux image and run valgrind inside it."
  echo "   - Try Homebrew: brew install --HEAD valgrind (may fail on newer macOS)."
  echo
  echo "If you have Docker, run an Ubuntu container, install valgrind there and run the binary inside the container."
  exit 127
fi

if [ ! -x ./push_swap ]; then
  echo "Binary ./push_swap not found or not executable. Run 'make' first." >&2
  exit 1
fi

# Run valgrind with provided args
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "$@"
