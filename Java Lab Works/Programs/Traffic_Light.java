 
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class  Traffic_Light  extends JFrame implements ActionListener {
    private JPanel lightPanel;
    private JRadioButton redButton, yellowButton, greenButton;

    public Traffic_Light() {
        // Set up the frame
        setTitle("Traffic Light Simulator");
        setSize(300, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create a panel for the traffic light
        lightPanel = new JPanel();
        lightPanel.setLayout(new GridLayout(3, 1));
        lightPanel.setPreferredSize(new Dimension(100, 300));
        
        // Create lights
        JPanel redLight = createLightPanel(Color.RED);
        JPanel yellowLight = createLightPanel(Color.YELLOW);
        JPanel greenLight = createLightPanel(Color.GREEN);
        
        lightPanel.add(redLight);
        lightPanel.add(yellowLight);
        lightPanel.add(greenLight);
        
        // Create radio buttons
        redButton = new JRadioButton("Red Light");
        yellowButton = new JRadioButton("Yellow Light");
        greenButton = new JRadioButton("Green Light");
        
        // Group the radio buttons so that only one can be selected at a time
        ButtonGroup group = new ButtonGroup();
        group.add(redButton);
        group.add(yellowButton);
        group.add(greenButton);

        // Add action listeners
        redButton.addActionListener(this);
        yellowButton.addActionListener(this);
        greenButton.addActionListener(this);
        
        // Create a panel for the buttons
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(3, 1));
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);
        
        // Add panels to the frame
        add(lightPanel, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
        
        // Initialize the lights
        turnOffAllLights();
    }

    private JPanel createLightPanel(Color color) {
        JPanel panel = new JPanel();
        panel.setBackground(Color.GRAY); // Set default background
        panel.setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
        panel.setPreferredSize(new Dimension(100, 100));
        panel.setOpaque(true);
        panel.setVisible(true);
        return panel;
    }

    private void turnOffAllLights() {
        for (Component comp : lightPanel.getComponents()) {
            comp.setBackground(Color.GRAY); // Reset all lights to gray
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        turnOffAllLights(); // Turn off all lights first
        
        if (e.getSource() == redButton) {
            lightPanel.getComponent(0).setBackground(Color.RED); // Turn on red light
        } else if (e.getSource() == yellowButton) {
            lightPanel.getComponent(1).setBackground(Color.YELLOW); // Turn on yellow light
        } else if (e.getSource() == greenButton) {
            lightPanel.getComponent(2).setBackground(Color.GREEN); // Turn on green light
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Traffic_Light simulator = new Traffic_Light();
            simulator.setVisible(true);
        });
    }
}
