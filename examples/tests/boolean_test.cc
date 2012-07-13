// Copyright 2011-2012 Google
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "base/hash.h"
#include "base/map-util.h"
#include "base/stl_util.h"
#include "base/random.h"
#include "constraint_solver/constraint_solveri.h"
#include "constraint_solver/constraint_solver.h"
#include "constraint_solver/model.pb.h"
#include "util/string_array.h"

namespace operations_research {
class SatPropagator;
bool AddBoolEq(SatPropagator* const sat,
               IntExpr* const left,
               IntExpr* const right);

bool AddBoolLe(SatPropagator* const sat,
               IntExpr* const left,
               IntExpr* const right);

bool AddBoolNot(SatPropagator* const sat,
                IntExpr* const left,
                IntExpr* const right);

bool AddBoolAndArrayEqVar(SatPropagator* const sat,
                          const std::vector<IntVar*>& vars,
                          IntVar* const target);

bool AddBoolAndEqVar(SatPropagator* const sat,
                     IntVar* const left,
                     IntVar* const right,
                     IntVar* const target);

bool AddBoolOrEqVar(SatPropagator* const sat,
                    IntVar* const left,
                    IntVar* const right,
                    IntVar* const target);

bool AddBoolOrArrayEqualTrue(SatPropagator* const sat,
                             const std::vector<IntVar*>& vars);

bool AddBoolAndArrayEqualFalse(SatPropagator* const sat,
                               const std::vector<IntVar*>& vars);

SatPropagator* MakeSatPropagator(Solver* const solver);

void TestBoolEq() {
  LOG(INFO) << "TestBoolEq";
  Solver solver("TestBoolEq");
  SatPropagator* const sat = MakeSatPropagator(&solver);
  solver.AddConstraint(reinterpret_cast<Constraint*>(sat));
  IntVar* const x = solver.MakeBoolVar("x");
  IntVar* const y = solver.MakeBoolVar("y");
  CHECK(AddBoolEq(sat, x, solver.MakeDifference(1, y)));
  DecisionBuilder* const db =
      solver.MakePhase(x, y,
                       Solver::CHOOSE_FIRST_UNBOUND,
                       Solver::ASSIGN_MIN_VALUE);
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    LOG(INFO) << " x = " << x->Value() << ", y = " << y->Value();
  }
  solver.EndSearch();
  CHECK_EQ(2, solver.solutions());
  LOG(INFO) << solver.DebugString();
}

void TestBoolAndEq() {
  LOG(INFO) << "TestBoolAndEq";
  Solver solver("TestBoolAndEq");
  SatPropagator* const sat = MakeSatPropagator(&solver);
  solver.AddConstraint(reinterpret_cast<Constraint*>(sat));
  IntVar* const x = solver.MakeBoolVar("x");
  IntVar* const y = solver.MakeBoolVar("y");
  IntVar* const z = solver.MakeBoolVar("z");
  CHECK(AddBoolAndEqVar(sat, x, y, z));
  DecisionBuilder* const db =
      solver.MakePhase(x, y, z,
                       Solver::CHOOSE_FIRST_UNBOUND,
                       Solver::ASSIGN_MIN_VALUE);
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    LOG(INFO) << " x = " << x->Value()
              << ", y = " << y->Value()
              << ", z = " << z->Value();
  }
  solver.EndSearch();
  LOG(INFO) << solver.DebugString();
}

void TestBoolOrEq() {
  LOG(INFO) << "TestBoolOrEq";
  Solver solver("TestBoolOrEq");
  SatPropagator* const sat = MakeSatPropagator(&solver);
  solver.AddConstraint(reinterpret_cast<Constraint*>(sat));
  IntVar* const x = solver.MakeBoolVar("x");
  IntVar* const y = solver.MakeBoolVar("y");
  IntVar* const z = solver.MakeBoolVar("z");
  CHECK(AddBoolOrEqVar(sat, x, y, z));
  DecisionBuilder* const db =
      solver.MakePhase(x, y, z,
                       Solver::CHOOSE_FIRST_UNBOUND,
                       Solver::ASSIGN_MIN_VALUE);
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    LOG(INFO) << " x = " << x->Value()
              << ", y = " << y->Value()
              << ", z = " << z->Value();
  }
  solver.EndSearch();
  LOG(INFO) << solver.DebugString();
}
}  // namespace operations_research


int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  operations_research::TestBoolEq();
  operations_research::TestBoolAndEq();
  operations_research::TestBoolOrEq();
  return 0;
}