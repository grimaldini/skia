

/**************************************************************************************************
 *** This file was autogenerated from GrChildProcessorSampleCoords.fp; do not modify.
 **************************************************************************************************/
#include "GrChildProcessorSampleCoords.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLChildProcessorSampleCoords : public GrGLSLFragmentProcessor {
public:
    GrGLSLChildProcessorSampleCoords() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrChildProcessorSampleCoords& _outer = args.fFp.cast<GrChildProcessorSampleCoords>();
        (void) _outer;
        SkString _sample0 = this->invokeChild(0, args);
        SkString _coords1 = SkStringPrintf("%s / 2.0", args.fSampleCoord);
        SkString _sample1 = this->invokeChild(0, args, _coords1.c_str());
        fragBuilder->codeAppendf(
R"SkSL(return %s + %s;
)SkSL"
, _sample0.c_str(), _sample1.c_str());
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
    }
};
GrGLSLFragmentProcessor* GrChildProcessorSampleCoords::onCreateGLSLInstance() const {
    return new GrGLSLChildProcessorSampleCoords();
}
void GrChildProcessorSampleCoords::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
}
bool GrChildProcessorSampleCoords::onIsEqual(const GrFragmentProcessor& other) const {
    const GrChildProcessorSampleCoords& that = other.cast<GrChildProcessorSampleCoords>();
    (void) that;
    return true;
}
bool GrChildProcessorSampleCoords::usesExplicitReturn() const {
    return true;
}
GrChildProcessorSampleCoords::GrChildProcessorSampleCoords(const GrChildProcessorSampleCoords& src)
: INHERITED(kGrChildProcessorSampleCoords_ClassID, src.optimizationFlags()) {
        this->cloneAndRegisterAllChildProcessors(src);
    this->setUsesSampleCoordsDirectly();
}
std::unique_ptr<GrFragmentProcessor> GrChildProcessorSampleCoords::clone() const {
    return std::make_unique<GrChildProcessorSampleCoords>(*this);
}
#if GR_TEST_UTILS
SkString GrChildProcessorSampleCoords::onDumpInfo() const {
    return SkString();
}
#endif
