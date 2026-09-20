# Barrier Next roadmap

Barrier Next continues the Barrier/InputLeap code line as a small, approachable
open-source project. The working name may change before the first public release.

## v0.1 — Connect without guessing

- Build one current Windows x64 installer and one universal macOS installer.
- Explain common connection failures directly in the main window.
- Replace jargon-heavy setup text with role-based instructions.
- Keep encrypted connections enabled and make fingerprint approval understandable.
- Test a Windows server with a macOS client and the reverse arrangement.

## v0.2 — First-run connection assistant

- [x] Discover nearby servers by mDNS and keep the list in sync as computers
  join or leave the network.
- [x] Show live search state, automatic selection, and a one-click rescan with
  a clear manual-address fallback.
- Resolve and show each server's verified address next to its computer name.
- Validate that the server and client security modes match before connecting.
- Test whether TCP port 24800 is reachable and give firewall-specific guidance.
- Export a small, privacy-safe diagnostics report for bug reports.

## v0.3 — Maintainable releases

- Add signed and notarized macOS builds.
- Add signed Windows installers.
- Publish checksums and a software bill of materials with every release.
- Document the release process so a new contributor can reproduce it.

## Principles

- Secure defaults; no silent fallback to an unencrypted connection.
- Clear language before advanced terminology.
- Windows and macOS are release blockers for v0.1.
- Preserve GPLv2 attribution and upstream history.
