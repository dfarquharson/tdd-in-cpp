build:
	cmake --build cmake-build-debug --target cpp_playground -- -j 4

run:
	./cmake-build-debug/cpp_playground

test:
	time make build run
