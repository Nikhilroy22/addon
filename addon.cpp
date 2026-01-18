#include <napi.h>
#include <pty.h>
#include <unistd.h>

Napi::Number spawnShell(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  int masterFd;
  pid_t pid = forkpty(&masterFd, nullptr, nullptr, nullptr);

  if (pid == 0) {
    execl("/bin/bash", "bash", nullptr);
    _exit(1);
  }

  return Napi::Number::New(env, masterFd);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("spawnShell", Napi::Function::New(env, spawnShell));
  return exports;
}

NODE_API_MODULE(ptyaddon, Init)