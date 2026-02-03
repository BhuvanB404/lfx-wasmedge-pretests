#include <wasmedge/wasmedge.h>
#include <stdio.h>
#include <stdlib.h>

int main(int Argc, const char* Argv[]) {


  printf("------------Pretest 2 start ---------------------\n");

  /* configuration and Vm creation */
  WasmEdge_ConfigureContext *ConfCxt = WasmEdge_ConfigureCreate();
  WasmEdge_ConfigureAddHostRegistration(ConfCxt, WasmEdge_HostRegistration_Wasi);
  WasmEdge_VMContext *vm = WasmEdge_VMCreate(ConfCxt, NULL);

  /* Setting parameters for fib : Argv[2]: the number n */
  WasmEdge_Value params[1] = { WasmEdge_ValueGenI32(atoi(Argv[2])) };
  WasmEdge_Value returns[1];

  /* reference to the function name in file */
  WasmEdge_String func = WasmEdge_StringCreateByCString("fib");

  /* results of the function exectution */
  WasmEdge_Result res = WasmEdge_VMRunWasmFromFile(vm, Argv[1], func, params, 1, returns, 1);

  if (WasmEdge_ResultOK(res)) {
    printf("Result: %d\n", WasmEdge_ValueGetI32(returns[0]));
  } else {
    printf("Error message: %s\n", WasmEdge_ResultGetMessage(res));
  }

  printf("--------------- Pretest End  -------------------\n");

  /* Resources deallocations */
  WasmEdge_VMDelete(vm);
  WasmEdge_ConfigureDelete(ConfCxt);
  WasmEdge_StringDelete(func);
  return 0;
}