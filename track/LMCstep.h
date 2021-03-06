#ifndef __LMCstep_
#define __LMCstep_

#include <vector>
#include <TVector3.h>
#include <TParticle.h>
using namespace std;

class TGeoNode;
class TGeoMaterial;
class TGeoMedium;

//////////////////////////////////////////////////////////////////////////////////////////
class LMCstep {
 public:
  LMCstep();
  ~LMCstep();
  void SetEnergy(Double_t);
  void SetEnergyLost(Double_t);
  void SetEnergyLostIoniz(Double_t);
  void SetEnergyLostCerenk(Double_t);
  void SetCurrentNode(TGeoNode *n);
  void SetCurrentMedium(TGeoMedium *n);
  void SetCurrentMaterial(TGeoMaterial *n);
  void SetInitPoint(TVector3 v);
  void SetEndPoint(TVector3 v); 
  void SetNPhotonsSci(Int_t n); 
  void SetNPhotonsCer(Int_t n); 
  void SetCerAngle(Double_t);
  void AddParticle(TParticle *p) {vparticles.push_back(p);}
  void SetNewParticles();

  Double_t GetEnergy();
  Double_t GetEnergyLost();
  Double_t GetEnergyLostIoniz();
  Double_t GetEnergyLostCerenk();
  TGeoNode* GetCurrentNode();
  TGeoMedium* GetCurrentMedium();
  TGeoMaterial* GetCurrentMaterial();
  const TVector3 GetInitPoint();
  const TVector3 GetEndPoint(); 
  Double_t GetStepLength();
  Int_t GetNPhotonsSci(); 
  Int_t GetNPhotonsCer(); 
  Double_t GetCerAngle();
  vector<TParticle*> GetParticles() {return vparticles;} 

  void Dump();

 private:
  double Energy_i; ///< Total initial energy (GeV)
  double Energy_lost; ///< total energy lost by particle in the step (MeV)
  double dE_ioniz;  ///< energy lost by particle through ionization (dE/dx)
  double dE_cerenk; ///< energy lost by particle through cerenkov radiation
  TGeoNode *CurrentNode; ///< current node
  TGeoMedium *CurrentMedium; ///< current medium
  TGeoMaterial *CurrentMaterial; ///< current material  
  TVector3 InitPoint; ///<begin step point 
  TVector3 EndPoint; ///<end step point 
  int NPhotonsSci; ///< number of scintillating photons produced along the step
  int NPhotonsCer; ///< number of cerenkov photons produced along the step
  double thetaCer; ///< Cerenkov angle
  vector<TParticle*> vparticles; ///<particles produced along the step  
};

#endif
