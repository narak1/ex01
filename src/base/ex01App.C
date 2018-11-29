#include "ex01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ex01App>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ex01App::ex01App(InputParameters parameters) : MooseApp(parameters)
{
  ex01App::registerAll(_factory, _action_factory, _syntax);
}

ex01App::~ex01App() {}

void
ex01App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"ex01App"});
  Registry::registerActionsTo(af, {"ex01App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ex01App::registerApps()
{
  registerApp(ex01App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ex01App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ex01App::registerAll(f, af, s);
}
extern "C" void
ex01App__registerApps()
{
  ex01App::registerApps();
}
