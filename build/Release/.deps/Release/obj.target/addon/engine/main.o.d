cmd_Release/obj.target/addon/engine/main.o := g++ -o Release/obj.target/addon/engine/main.o ../engine/main.cc '-DNODE_GYP_MODULE_NAME=addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-DV8_DEPRECATION_WARNINGS' '-DV8_IMMINENT_DEPRECATION_WARNINGS' '-D_GLIBCXX_USE_CXX11_ABI=1' '-DELECTRON_ENSURE_CONFIG_GYPI' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DUSING_ELECTRON_CONFIG_GYPI' '-DV8_COMPRESS_POINTERS' '-DV8_COMPRESS_POINTERS_IN_SHARED_CAGE' '-DV8_ENABLE_SANDBOX' '-DV8_SANDBOXED_POINTERS' '-DV8_31BIT_SMIS_ON_64BIT_ARCH' '-DV8_REVERSE_JSARGS' '-D__STDC_FORMAT_MACROS' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DOPENSSL_NO_ASM' '-DBUILDING_NODE_EXTENSION' -I/home/cardonapablo/.electron-gyp/21.1.0/include/node -I/home/cardonapablo/.electron-gyp/21.1.0/src -I/home/cardonapablo/.electron-gyp/21.1.0/deps/openssl/config -I/home/cardonapablo/.electron-gyp/21.1.0/deps/openssl/openssl/include -I/home/cardonapablo/.electron-gyp/21.1.0/deps/uv/include -I/home/cardonapablo/.electron-gyp/21.1.0/deps/zlib -I/home/cardonapablo/.electron-gyp/21.1.0/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -std=gnu++14 -MMD -MF ./Release/.deps/Release/obj.target/addon/engine/main.o.d.raw  -std=c++17 -c
Release/obj.target/addon/engine/main.o: ../engine/main.cc \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/node.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/cppgc/common.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8config.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-array-buffer.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-local-handle.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-internal.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-version.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8config.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-object.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-maybe.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-persistent-handle.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-weak-callback-info.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-primitive.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-data.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-value.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-traced-handle.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-container.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-context.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-snapshot.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-date.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-debug.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-script.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-message.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-exception.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-extension.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-external.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-function.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-function-callback.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-template.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-memory-span.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-initialization.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-callbacks.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-promise.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-isolate.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-embedder-heap.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-microtask.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-statistics.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-unwinder.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-embedder-state-scope.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-platform.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-json.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-locker.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-microtask-queue.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-primitive-object.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-proxy.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-regexp.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-typed-array.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-value-serializer.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-wasm.h \
 /home/cardonapablo/.electron-gyp/21.1.0/include/node/node_version.h
../engine/main.cc:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/node.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/cppgc/common.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8config.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-array-buffer.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-local-handle.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-internal.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-version.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8config.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-object.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-maybe.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-persistent-handle.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-weak-callback-info.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-primitive.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-data.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-value.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-traced-handle.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-container.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-context.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-snapshot.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-date.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-debug.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-script.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-message.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-exception.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-extension.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-external.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-function.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-function-callback.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-template.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-memory-span.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-initialization.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-callbacks.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-promise.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-isolate.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-embedder-heap.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-microtask.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-statistics.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-unwinder.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-embedder-state-scope.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-platform.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-json.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-locker.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-microtask-queue.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-primitive-object.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-proxy.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-regexp.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-typed-array.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-value-serializer.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/v8-wasm.h:
/home/cardonapablo/.electron-gyp/21.1.0/include/node/node_version.h:
