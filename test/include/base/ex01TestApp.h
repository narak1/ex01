//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef EX01TESTAPP_H
#define EX01TESTAPP_H

#include "MooseApp.h"

class ex01TestApp;

template <>
InputParameters validParams<ex01TestApp>();

class ex01TestApp : public MooseApp
{
public:
  ex01TestApp(InputParameters parameters);
  virtual ~ex01TestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* EX01TESTAPP_H */
