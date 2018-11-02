type t;

[@bs.deriving abstract]
type createOptions = {
  domain: string,
  clientID: string,
  [@bs.optional]
  responseType: string,
  [@bs.optional]
  responseMode: string,
  [@bs.optional]
  redirectUri: string,
  [@bs.optional]
  scope: string,
  [@bs.optional]
  audience: string,
  [@bs.optional]
  leeway: float,
};

[@bs.deriving abstract]
type authorizeOptions = {
  [@bs.optional]
  domain: string,
  [@bs.optional]
  clientID: string,
  [@bs.optional]
  connection: string,
  [@bs.optional]
  responseType: string,
  [@bs.optional]
  responseMode: string,
  [@bs.optional]
  redirectUri: string,
  [@bs.optional]
  scope: string,
  [@bs.optional]
  state: string,
  [@bs.optional]
  nonce: string,
  [@bs.optional]
  audience: string,
  [@bs.optional]
  language: string,
  [@bs.optional]
  leeway: float,
};

[@bs.deriving abstract]
type renewOptions = {
  [@bs.optional]
  domain: string,
  [@bs.optional]
  clientID: string,
  [@bs.optional]
  responseType: string,
  [@bs.optional]
  responseMode: string,
  [@bs.optional]
  redirectUri: string,
  [@bs.optional]
  state: string,
  [@bs.optional]
  nonce: string,
  [@bs.optional]
  scope: string,
  [@bs.optional]
  audience: string,
  [@bs.optional]
  leeway: float,
};

[@bs.deriving abstract]
type logoutOptions = {
  [@bs.optional]
  clientID: string,
  [@bs.optional]
  returnTo: string,
  [@bs.optional]
  federated: bool,
};

[@bs.deriving abstract]
type idToken = {
  aud: string,
  exp: float,
  iat: float,
  iss: string,
  sub: string,
  [@bs.optional]
  name: string,
  [@bs.optional]
  email: string,
  [@bs.optional]
  picture: string,
};

[@bs.deriving abstract]
type authResult =
  pri {
    [@bs.optional]
    accessToken: string,
    [@bs.optional]
    appState: string,
    expiresIn: float,
    [@bs.optional]
    idToken: string,
    [@bs.optional]
    idTokenPayload: idToken,
    [@bs.optional]
    refreshToken: string,
    [@bs.optional]
    scope: string,
    [@bs.optional]
    state: string,
    [@bs.optional]
    tokenType: string,
  };

[@bs.deriving abstract]
type authError =
  pri {
    error: string,
    errorDescription: string,
  };

type authCallback('a) =
  (Js.Nullable.t(authError), Js.Nullable.t('a)) => unit;

[@bs.new] [@bs.module "auth0-js"]
external createWebAuth: createOptions => t = "WebAuth";
[@bs.send] external authorize: t => unit = "";
[@bs.send]
external authorizeWithOptions: (t, authorizeOptions) => unit = "authorize";
[@bs.send] external parseHash: (t, authCallback(authResult)) => unit = "";
/* [@bs.send] external parseHashWithOptions: (t, parseHashOptions, authCallback(authResult)) => unit = "parseHash"; */
[@bs.send] external logoutWithOptions: (t, logoutOptions) => unit = "logout";
[@bs.send]
external renewAuthWithOptions:
  (t, renewOptions, authCallback(authResult)) => unit =
  "renewAuth";
