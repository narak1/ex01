//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ex01TestApp.h"
#include "ex01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<ex01TestApp>()
{
  InputParameters params = validParams<ex01App>();
  return params;
}

ex01TestApp::ex01TestApp(InputParameters parameters) : MooseApp(parameters)
{
  ex01TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ex01TestApp::~ex01TestApp() {}

void
ex01TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ex01App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ex01TestApp"});
    Registry::registerActionsTo(af, {"ex01TestApp"});
  }
}

void
ex01TestApp::registerApps()
{
  registerApp(ex01App);
  registerApp(ex01TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ex01TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ex01TestApp::registerAll(f, af, s);
}
extern "C" void
ex01TestApp__registerApps()
{
  ex01TestApp::registerApps();
}
