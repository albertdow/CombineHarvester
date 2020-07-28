import FWCore.ParameterSet.Config as cms
process = cms.Process("MAIN")

process.source = cms.Source("EmptySource")
process.options   = cms.untracked.PSet(
    numberOfThreads = cms.untracked.uint32(2)
)
