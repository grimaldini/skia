

/**************************************************************************************************
 *** This file was autogenerated from GrChildProcessorsWithInput.fp; do not modify.
 **************************************************************************************************/
#include "GrChildProcessorsWithInput.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLChildProcessorsWithInput : public GrGLSLFragmentProcessor {
public:
    GrGLSLChildProcessorsWithInput() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrChildProcessorsWithInput& _outer = args.fFp.cast<GrChildProcessorsWithInput>();
        (void) _outer;
        colorVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag, kHalf4_GrSLType, "color");
        fragBuilder->codeAppendf(
R"SkSL(half4 childIn = %s;)SkSL"
, args.fUniformHandler->getUniformCStr(colorVar));
        SkString _input0("childIn");
        SkString _sample0 = this->invokeChild(0, _input0.c_str(), args);
        fragBuilder->codeAppendf(
R"SkSL(
half4 childOut1 = %s;)SkSL"
, _sample0.c_str());
        SkString _input1("childOut1");
        SkString _sample1 = this->invokeChild(1, _input1.c_str(), args);
        fragBuilder->codeAppendf(
R"SkSL(
half4 childOut2 = %s;
return childOut2;
)SkSL"
, _sample1.c_str());
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
    }
    UniformHandle colorVar;
};
GrGLSLFragmentProcessor* GrChildProcessorsWithInput::onCreateGLSLInstance() const {
    return new GrGLSLChildProcessorsWithInput();
}
void GrChildProcessorsWithInput::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
}
bool GrChildProcessorsWithInput::onIsEqual(const GrFragmentProcessor& other) const {
    const GrChildProcessorsWithInput& that = other.cast<GrChildProcessorsWithInput>();
    (void) that;
    return true;
}
bool GrChildProcessorsWithInput::usesExplicitReturn() const {
    return true;
}
GrChildProcessorsWithInput::GrChildProcessorsWithInput(const GrChildProcessorsWithInput& src)
: INHERITED(kGrChildProcessorsWithInput_ClassID, src.optimizationFlags()) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrChildProcessorsWithInput::clone() const {
    return std::make_unique<GrChildProcessorsWithInput>(*this);
}
#if GR_TEST_UTILS
SkString GrChildProcessorsWithInput::onDumpInfo() const {
    return SkString();
}
#endif
