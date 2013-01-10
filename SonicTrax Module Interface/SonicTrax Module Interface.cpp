// SonicTrax Module Interface.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SonicTrax Module Interface.h"
#include "Effects.h"

using namespace Effects;

#include <iostream>

// This is an example of an exported function.
SONICTRAXMODULEINTERFACE_API std::string test(void)
{
	LeafEffect sum("sum","return { (a + b) };");
	sum.inputs.push_back(new InputEndpoint("a"));
	sum.inputs.push_back(new InputEndpoint("b"));
	sum.outputs.push_back(new OutputEndpoint("result"));

	LeafEffect sub("sub","return { (a - b) };");
	sub.inputs.push_back(new InputEndpoint("a"));
	sub.inputs.push_back(new InputEndpoint("b"));
	sub.outputs.push_back(new OutputEndpoint("result"));

	LeafEffect mul("mul","return { (a * b) };");
	mul.inputs.push_back(new InputEndpoint("a"));
	mul.inputs.push_back(new InputEndpoint("b"));
	mul.outputs.push_back(new OutputEndpoint("result"));

	LeafEffect div("div","return { (a / b) };");
	div.inputs.push_back(new InputEndpoint("a"));
	div.inputs.push_back(new InputEndpoint("b"));
	div.outputs.push_back(new OutputEndpoint("result"));

	CompositeEffect avg("avg");
	avg.inputs.push_back(new InputEndpoint("a"));
	avg.inputs.push_back(new InputEndpoint("b"));
	avg.outputs.push_back(new OutputEndpoint("result"));

	EffectInstance ei(sum);
	ei.inputs.push_back(new EntranceBoundInputEndpointInstance(avg,0));
	ei.inputs.push_back(new EntranceBoundInputEndpointInstance(avg,1));

	EffectInstance ei2(div);
	ei2.inputs.push_back(new BoundInputEndpointInstance(OutputBinding(ei,0)));
	ei2.inputs.push_back(new StaticNumberInputEndpointInstance(2.0f));

	avg.exit_bindings.push_back(new BoundInputEndpointInstance(OutputBinding(ei2,0)));

	CompositeEffect tester("tester");
	tester.inputs.push_back(new InputEndpoint("fer"));
	tester.inputs.push_back(new InputEndpoint("jui"));
	tester.outputs.push_back(new OutputEndpoint("result"));
	tester.outputs.push_back(new OutputEndpoint("ignore"));

	EffectInstance ei4(sub);
	ei4.inputs.push_back(new EntranceBoundInputEndpointInstance(tester,0));
	ei4.inputs.push_back(new StaticNumberInputEndpointInstance(8.0f));

	EffectInstance ei3(avg);
	ei3.inputs.push_back(new BoundInputEndpointInstance(OutputBinding(ei4,0)));
	ei3.inputs.push_back(new EntranceBoundInputEndpointInstance(tester,1));

	tester.exit_bindings.push_back(new BoundInputEndpointInstance(OutputBinding(ei3,0)));
	tester.exit_bindings.push_back(new StaticNumberInputEndpointInstance(34.48725f));


	TotalCompilationContext tcc;
	tester.Compile(tcc);

	return tcc.GetCode();
}


