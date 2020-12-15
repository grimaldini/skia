

/**************************************************************************************************
 *** This file was autogenerated from GrChildProcessorSampleMatrixSingleUniformExpr.fp; do not modify.
 **************************************************************************************************/
#include "GrChildProcessorSampleMatrixSingleUniformExpr.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLChildProcessorSampleMatrixSingleUniformExpr : public GrGLSLFragmentProcessor {
public:
    GrGLSLChildProcessorSampleMatrixSingleUniformExpr() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrChildProcessorSampleMatrixSingleUniformExpr& _outer = args.fFp.cast<GrChildProcessorSampleMatrixSingleUniformExpr>();
        (void) _outer;
        matrixVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag, kFloat3x3_GrSLType, "matrix");
        SkString _matrix0 = SkStringPrintf("0.5 * %s", args.fUniformHandler->getUniformCStr(matrixVar));
        SkString _sample0 = this->invokeChildWithMatrix(0, args, _matrix0.c_str());
        fragBuilder->codeAppendf(
R"SkSL(return %s;
)SkSL"
, _sample0.c_str());
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
    }
    UniformHandle matrixVar;
};
GrGLSLFragmentProcessor* GrChildProcessorSampleMatrixSingleUniformExpr::onCreateGLSLInstance() const {
    return new GrGLSLChildProcessorSampleMatrixSingleUniformExpr();
}
void GrChildProcessorSampleMatrixSingleUniformExpr::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
}
bool GrChildProcessorSampleMatrixSingleUniformExpr::onIsEqual(const GrFragmentProcessor& other) const {
    const GrChildProcessorSampleMatrixSingleUniformExpr& that = other.cast<GrChildProcessorSampleMatrixSingleUniformExpr>();
    (void) that;
    return true;
}
bool GrChildProcessorSampleMatrixSingleUniformExpr::usesExplicitReturn() const {
    return true;
}
GrChildProcessorSampleMatrixSingleUniformExpr::GrChildProcessorSampleMatrixSingleUniformExpr(const GrChildProcessorSampleMatrixSingleUniformExpr& src)
: INHERITED(kGrChildProcessorSampleMatrixSingleUniformExpr_ClassID, src.optimizationFlags()) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrChildProcessorSampleMatrixSingleUniformExpr::clone() const {
    return std::make_unique<GrChildProcessorSampleMatrixSingleUniformExpr>(*this);
}
#if GR_TEST_UTILS
SkString GrChildProcessorSampleMatrixSingleUniformExpr::onDumpInfo() const {
    return SkString();
}
#endif
