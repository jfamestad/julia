import _julia
import matplotlib.pyplot as plt

class Julia:
    def __init__(self, min_r, max_r, min_i, max_i, z, resolution):
            self.scores = _julia.Julia(min_r, max_r, min_i, max_i, z, resolution)
            self._julia = None

    @property
    def julia(self):
        if not self._julia:
            self._julia = [c for c in self.scores if self.scores[c] == 101]
        return self._julia

    def render_julia(self):
        real = [c.real for c in self.julia]
        imag = [c.imag for c in self.julia]
        plt.scatter(real, imag, s=.0001)
        plt.show()

    def render(self):
        elements = [c for c in self.scores if not c in self.julia]
        real = [c.real for c in elements]
        imag = [c.imag for c in elements]
        scores = [(.5, 1 - self.scores[c]/101, self.scores[c]/101) for c in elements]
        plt.scatter(real, imag, c=scores, s=.01)
        plt.show()
