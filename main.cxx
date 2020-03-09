#include <iostream>

#include <TApplication.h>
#include <TGraph.h>
#include "TMagQualLogger.h"


int main(int argc, char** argv)
{

  LOG_STATUS( "sss" );

  TApplication* app = new TApplication("app", &argc, argv);

  double x[2] = {1,2};
  double y[2] = {5,2};
 
  TGraph* gr = new TGraph(2,x,y);
  gr->Draw("ap"); 

  app->Run();

  delete gr;

  return 0;
}
