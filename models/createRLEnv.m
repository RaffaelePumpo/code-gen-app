function env = createRLEnv
        mdl = 'Env_RL';
        numAct       = 1;
        actInfo      = rlNumericSpec([numAct 1],'LowerLimit',-40,'UpperLimit', 40);
        actInfo.Name = 'torque';
        numObs       = 3;
        obsInfo      = rlNumericSpec([numObs 1]);
        obsInfo.Name = 'observations';
        load_system(mdl);
        blockPath = [mdl,'/Agente'];
        env = rlSimulinkEnv(mdl,blockPath,obsInfo,actInfo);
        env.ResetFcn = @(in)setVariable(in,"theta0",0,"Workspace",mdl);
end