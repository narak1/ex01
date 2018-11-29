//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef EX01APP_H
#define EX01APP_H

#include "MooseApp.h"

class ex01App;

template <>
InputParameters validParams<ex01App>();

class ex01App : public MooseApp
{
public:
  ex01App(InputParameters parameters);
  virtual ~ex01App();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* EX01APP_H */
