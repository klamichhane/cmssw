/* \class EtaPtMinPdgIdCandSelector
 * 
 * Candidate Selector based on a minimum pt cut and an eta range.
 * Usage:
 * 
 * module selectedCands = EtaPtMinPdgIdCandSelector {
 *   InputTag src = myCollection
 *   double ptMin = 15.0
 *   double etaMin = -2
 *   double etaMax = 2
 *   int pdgId = 11
 * };
 *
 * \author: Luca Lista, INFN
 *
 */
#include "FWCore/Framework/interface/MakerMacros.h"
#include "PhysicsTools/UtilAlgos/interface/ObjectSelector.h"
#include "PhysicsTools/UtilAlgos/interface/SingleElementCollectionSelector.h"
#include "PhysicsTools/UtilAlgos/interface/PtMinSelector.h"
#include "PhysicsTools/UtilAlgos/interface/EtaRangeSelector.h"
#include "PhysicsTools/UtilAlgos/interface/PdgIdSelector.h"
#include "PhysicsTools/UtilAlgos/interface/AndSelector.h"
#include "DataFormats/Candidate/interface/Candidate.h"

typedef ObjectSelector<
          SingleElementCollectionSelector<
            reco::CandidateCollection,
            AndSelector<
              PtMinSelector<reco::Candidate>,
              EtaRangeSelector<reco::Candidate>,
              PdgIdSelector<reco::Candidate>
            >
          >
        > EtaPtMinPdgIdCandSelector;

DEFINE_FWK_MODULE( EtaPtMinPdgIdCandSelector );
