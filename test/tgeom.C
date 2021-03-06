#include "LMCgeomN.h"
#include "LMCpropagator.h"
#include <vector>
#include "TParticle.h"
using namespace std;

int main() {
  double vtx[3] = {0.,0.,60.};
  double mom[3] = {0.,0.,-10.};
  int PID = 13;

  LMCgeomN *g = new LMCgeomN("Telescope");
  LMCpropagator *prop = new LMCpropagator(g->GetGeoManager());
    TParticle *particle = new TParticle(PID,0,0,0,0,0,mom[0],mom[1],mom[2],0.,vtx[0],vtx[1],vtx[2],0.);
    prop->SetParticle(particle);
    vector<LMCstep*> v = prop->Follow();

  return 0;
}

